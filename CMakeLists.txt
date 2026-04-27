cmake_minimum_required(VERSION 4.2.0)

project(klogger LANGUAGES CXX VERSION 4.21.26)

add_library(${PROJECT_NAME} STATIC src/klogger.cpp)

target_include_directories(${PROJECT_NAME}
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
        $<INSTALL_INTERFACE:src>
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_23)

include(FetchContent)

FetchContent_Declare(
        kasciicolor
        GIT_REPOSITORY https://github.com/KatzaCat/kasciicolor
        GIT_TAG        master
)

FetchContent_MakeAvailable(kasciicolor)

add_library(klogger::klogger ALIAS ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} PRIVATE kasciicolor::kasciicolor)

if(KL_ISTESTING)
        enable_testing()
        add_subdirectory(tests)
endif()
