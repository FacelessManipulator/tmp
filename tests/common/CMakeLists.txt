# CMakeLists for src directory

configure_file(hvs.conf.in /tmp/hvs/hvs.conf)
ADD_EXECUTABLE(unittest_config config.cc)
TARGET_LINK_LIBRARIES(unittest_config gtest gtest_main)
ADD_TEST(NAME unittest_config COMMAND unittest_config)
