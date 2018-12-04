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

TEST(ConfigTest, TestParseString)
{
    Config::parse("ConfigTest.conf");
    Config::dump();
    EXPECT_EQ(10, Config::get<int>("common.threads_num"));
}
