cmake_minimum_required(VERSION 4.2.0)

project(klogger LANGUAGES CXX VERSION 4.16.26)

add_library(${PROJECT_NAME} STATIC 
  src/klogger.cpp
)
target_include_directories(${PROJECT_NAME} PUBLIC src/)

if(KL_ISTESTING)
  enable_testing()
  add_subdirectory(test)
endif()
