add_executable(KLE_basic basic.cpp)
add_executable(KLE_push push.cpp)
add_executable(KLE_critical critical.cpp)
add_executable(KLE_file file.cpp)
add_executable(KLE_reformatting reformatting.cpp)

set_target_properties(KLE_basic PROPERTIES CXX_STANDARD 23)
set_target_properties(KLE_push PROPERTIES CXX_STANDARD 23)
set_target_properties(KLE_critical PROPERTIES CXX_STANDARD 23)
set_target_properties(KLE_file PROPERTIES CXX_STANDARD 23)
set_target_properties(KLE_reformatting PROPERTIES CXX_STANDARD 23)

target_link_libraries(KLE_basic PRIVATE klogger stdc++exp)
target_link_libraries(KLE_push PRIVATE klogger stdc++exp)
target_link_libraries(KLE_critical PRIVATE klogger stdc++exp)
target_link_libraries(KLE_file PRIVATE klogger stdc++exp)
target_link_libraries(KLE_reformatting PRIVATE klogger stdc++exp)

add_test(KLT_basic KLE_basic)
add_test(KLT_push KLE_push)
add_test(KLT_critical KLE_critical) # Itended to fail
add_test(KLT_file KLE_file)
add_test(KLT_reformatting KLE_reformatting)

