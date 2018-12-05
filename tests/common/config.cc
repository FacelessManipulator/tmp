#include "common/config.h"
#include "gtest/gtest.h"
class ConfigTest : public testing::Test
{
  protected:
    void SetUp() override {
        start_time_ = time(nullptr);
    }
    void TearDown() override
    {
        const time_t end_time = time(nullptr);

        EXPECT_TRUE(end_time - start_time_ <= 5) << "The test took too long.";
    }

    // The UTC time (in seconds) when the test starts
    time_t start_time_;
};

TEST(ConfigTest, TestParse)
{
    EXPECT_EQ(true, Config::parse("/tmp/hvs/hvs.conf"));
    EXPECT_EQ(10, Config::get<int>("common.threads_num"));
    EXPECT_STREQ("conf test", Config::get<std::string>("common.threads_name").c_str());
    EXPECT_EQ(true, Config::get<bool>("zone.auto_create"));
    EXPECT_FLOAT_EQ(0.5, Config::get<float>("zone.sync_timeout"));
}

TEST(ConfigTest, TestReSet)
{
    Config::set<int>("common.threads_num", 12);
    EXPECT_EQ(12, Config::get<int>("common.threads_num"));
    Config::set<std::string>("common.threads_name", "conf test2");
    EXPECT_STREQ("conf test2", Config::get<std::string>("common.threads_name").c_str());
    Config::set<bool>("zone.auto_create", false);
    EXPECT_EQ(false, Config::get<bool>("zone.auto_create"));
    Config::set<float>("zone.sync_timeout", 0.66);
    EXPECT_FLOAT_EQ(0.66, Config::get<float>("zone.sync_timeout"));
}

TEST(ConfigTest, TestReparse)
{
    Config::parse("/tmp/hvs/hvs.conf");
    EXPECT_EQ(10, Config::get<int>("common.threads_num"));
    EXPECT_STREQ("conf test", Config::get<std::string>("common.threads_name").c_str());
    EXPECT_EQ(true, Config::get<bool>("zone.auto_create"));
    EXPECT_FLOAT_EQ(0.5, Config::get<float>("zone.sync_timeout"));
}

TEST(ConfigTest, TestErrorReparse) {
    // Config shouldn't replace old profile with damaged profile
    Config::parse("/tmp/hvs/hvs.conf");
    EXPECT_NO_THROW({Config::parse("/tmp/hvs/hvs2.conf");}); // file not exists
    EXPECT_NO_THROW({Config::parse("/tmp/hvs/hvs_damage.json");}); // wrong format
    EXPECT_EQ(10, Config::get<int>("common.threads_num"));
}

TEST(ConfigTest, TestDump)
{
    
}