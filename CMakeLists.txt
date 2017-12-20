# %Tag(FULLTEXT)%
cmake_minimum_required(VERSION 2.8.3)
project(beginner_tutorials)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg message_generation)

## Declare ROS messages and services
add_message_files(FILES number.msg intlist.msg)
##add_service_files(FILES AddTwoInts.srv)

## Generate added messages and services
generate_messages(DEPENDENCIES std_msgs)

## Declare a catkin package
catkin_package()

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(generator src/generator.cpp)
target_link_libraries(generator ${catkin_LIBRARIES})
add_dependencies(generator random_gen_generate_messages_cpp)

add_executable(acceptor src/acceptor.cpp)
target_link_libraries(acceptor ${catkin_LIBRARIES})
add_dependencies(acceptor random_gen_generate_messages_cpp)


# %EndTag(FULLTEXT)%
