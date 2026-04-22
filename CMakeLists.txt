cmake_minimum_required(VERSION 4.2.0)

project(klogger LANGUAGES CXX VERSION 4.21.26)

add_library(${PROJECT_NAME} STATIC 
  src/klogger.cpp
)

set_target_properties(${PROJECT_NAME} PROPERTIES
  CXX_STANDARD 23
)

target_include_directories(${PROJECT_NAME} PUBLIC src/)
if (MINGW AND CMAKE_CXX_COMPILER_ID STREQUAL GNU)
  target_link_libraries(${PROJECT_NAME} stdc++exp) # std:: print, println, ...
endif()

if(KL_ISTESTING)
  enable_testing()
  add_subdirectory(tests)
endif()
