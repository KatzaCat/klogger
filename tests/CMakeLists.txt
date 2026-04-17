add_executable(KLE_basic basic.cpp)
add_executable(KLE_push push.cpp)

target_link_libraries(KLE_basic PRIVATE klogger)
target_link_libraries(KLE_push PRIVATE klogger)

add_test(KLT_basic COMMAND KLE_basic)
add_test(KLT_psuh COMMAND KLE_psuh)

