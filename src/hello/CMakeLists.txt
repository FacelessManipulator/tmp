# CMakeLists for module hello directory

SET(HELLO_SRCS
	hello.cc
)

# shared library
#ADD_LIBRARY(hello SHARED ${HELLO_SRCS})

# static library
ADD_LIBRARY(hello STATIC ${HELLO_SRCS})
