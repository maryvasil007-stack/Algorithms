add_executable(Lab3 lab3.cpp)

target_include_directories(Lab3 PRIVATE "${CMAKE_SOURCE_DIR}/LibraryCPP")

target_link_libraries(Lab3 PRIVATE LibraryCPP)

enable_testing()

add_test(NAME Lab3_Example COMMAND Lab3 ${CMAKE_CURRENT_SOURCE_DIR}/test_example.txt)
set_property(TEST Lab3_Example PROPERTY PASS_REGULAR_EXPRESSION "1 3 2")

add_test(NAME Lab3_Test1 COMMAND Lab3 ${CMAKE_CURRENT_SOURCE_DIR}/test1.txt)
set_property(TEST Lab3_Test1 PROPERTY PASS_REGULAR_EXPRESSION "1 2 3")

add_test(NAME Lab3_Test2 COMMAND Lab3 ${CMAKE_CURRENT_SOURCE_DIR}/test2.txt)
set_property(TEST Lab3_Test2 PROPERTY PASS_REGULAR_EXPRESSION "IMPOSSIBLE")

add_test(NAME Lab3_Test3 COMMAND Lab3 ${CMAKE_CURRENT_SOURCE_DIR}/test3.txt)
set_property(TEST Lab3_Test3 PROPERTY PASS_REGULAR_EXPRESSION "2")

add_test(NAME Lab3_Test4 COMMAND Lab3 ${CMAKE_CURRENT_SOURCE_DIR}/test4.txt)
set_property(TEST Lab3_Test4 PROPERTY PASS_REGULAR_EXPRESSION "1 3")

add_test(NAME Lab3_Test5 COMMAND Lab3 ${CMAKE_CURRENT_SOURCE_DIR}/test5.txt)
set_property(TEST Lab3_Test5 PROPERTY PASS_REGULAR_EXPRESSION "1 2 3")

add_test(NAME Lab3_Test6 COMMAND Lab3 ${CMAKE_CURRENT_SOURCE_DIR}/test6.txt)
set_property(TEST Lab3_Test6 PROPERTY PASS_REGULAR_EXPRESSION "1 2 3 4 5 6")