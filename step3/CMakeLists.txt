cmake_minimum_required (VERSION 3.3)
project (Tutorial)
#The version number
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# should we use our own math functions
option(USE_MYMATH "Use tutorial provided implementation" ON)

set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
		"${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
		"${PROJECT_BINARY_DIR}/TutorialConfig.h"
		)

# add the Mathfunctions library?
if(USE_MYMATH)
		add_subdirectory(MathFunctions)
		list(APPEND EXTRA_LIBS MathFunctions)
		list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MathFunctions")
endif(USE_MYMATH)


# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
#include_directories("${PROJECT_BINARY_DIR}")
#include_directories("${PROJECT_SOURCE_DIR}/MathFunctions")

#this uses relative path. It means go in here
#and build my library
#add_subdirectory (MathFunctions) 

# add the executable target called
#Tutorial from source tutorial.cxx
add_executable(Tutorial tutorial.cxx)
target_link_libraries (Tutorial ${EXTRA_LIBS})
target_include_directories (Tutorial PUBLIC ${PROJECT_BINARY_DIR}
		${EXTRA_INCLUDES})
