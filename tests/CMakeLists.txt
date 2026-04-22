add_executable(KLE_basic basic.cpp)
add_executable(KLE_push push.cpp)
add_executable(KLE_critical critical.cpp)
add_executable(KLE_file file.cpp)

target_link_libraries(KLE_basic PRIVATE klogger)
target_link_libraries(KLE_push PRIVATE klogger)
target_link_libraries(KLE_critical PRIVATE klogger)
target_link_libraries(KLE_file PRIVATE klogger)

add_test(KLT_basic KLE_basic)
add_test(KLT_push KLE_push)
add_test(KLT_critical KLE_critical) # Itended to fail
add_test(KLT_file KLE_file)

