# CMakeLists for src directory

ADD_EXECUTABLE(unittest_db test_db.cc)
TARGET_LINK_LIBRARIES(unittest_db gtest gtest_main db)
ADD_TEST(NAME unittest_db COMMAND unittest_db)
