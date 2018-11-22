# CMakeLists for src directory

ADD_SUBDIRECTORY(hello)

ADD_EXECUTABLE(playground main.cc)
TARGET_LINK_LIBRARIES(playground hello)
