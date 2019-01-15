cmake_minimum_required(VERSION 3.12)
project(linkedlist C)

set(CMAKE_C_STANDARD 11)

# have compiler give warnings, but not for signed/unsigned
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Wall -Wextra -Wno-sign-compare")

add_executable(linkedlist main.c linkedlist.c)