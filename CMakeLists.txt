cmake_minimum_required(VERSION 3.8)

project (geode_user_password_auth CXX)
set(CMAKE_BUILD_TYPE Release)
set (CMAKE_CXX_STANDARD 11)

add_library(geode_user_password_auth SHARED 
    src/user_password_auth_init.cpp
    src/user_password_auth_init.hpp)

target_link_libraries(geode_user_password_auth -lpivotal-gemfire)


