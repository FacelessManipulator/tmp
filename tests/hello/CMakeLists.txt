# CMakeLists for src directory

ADD_EXECUTABLE(unittest_hello test_hello.cc)
TARGET_LINK_LIBRARIES(unittest_hello gtest gtest_main hello)
ADD_TEST(NAME unittest_hello COMMAND unittest_hello)
