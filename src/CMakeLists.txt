project(hw3_library)

#add_definitions(-std=c++11)

file(GLOB_RECURSE SOURCE_FILES "*.cpp")
file(GLOB_RECURSE HEADER_FILES "*.h")


add_library(hw3_library STATIC ${SOURCE_FILES} ${HEADER_FILES})
