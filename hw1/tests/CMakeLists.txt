include_directories(${hw1_INCDIR})

add_executable(test_grandchild test_grandchild.cpp)
target_link_libraries(test_grandchild hw1 googletest )
add_test(PrintGrandchild ./test_grandchild)

add_executable(test_child test_child.cpp)
target_link_libraries(test_child hw1 googletest )
add_test(PrintChild ./test_child)

add_executable(test_parent test_parent.cpp)
target_link_libraries(test_parent hw1 googletest)
add_test(PrintParent ./test_parent)

add_executable(test_child_order test_child_order.cpp)
target_link_libraries(test_child_order hw1 googletest)
add_test(GCBeforeChild ./test_child_order)
add_test(GCBeforeChild ./test_child_order)
add_test(GCBeforeChild ./test_child_order)
add_test(GCBeforeChild ./test_child_order)
add_test(GCBeforeChild ./test_child_order)

add_executable(test_order test_order.cpp)
target_link_libraries(test_order hw1 googletest)
add_test(CorrectOrder ./test_order)
add_test(CorrectOrder ./test_order)
add_test(CorrectOrder ./test_order)
add_test(CorrectOrder ./test_order)
add_test(CorrectOrder ./test_order)

add_executable(test_schedule_calls0 test_schedule_calls0.cpp)
target_link_libraries(test_schedule_calls0 hw1 googletest )
add_test(RunAllJobs_Test0 ./test_schedule_calls0)

add_executable(test_schedule_calls1 test_schedule_calls1.cpp)
target_link_libraries(test_schedule_calls1 hw1 googletest )
add_test(RunAllJobs_Test1 ./test_schedule_calls1)

add_executable(test_schedule_calls2 test_schedule_calls2.cpp)
target_link_libraries(test_schedule_calls2 hw1 googletest )
add_test(RunAllJobs_Test2 ./test_schedule_calls2)


add_executable(test_schedule_order0 test_schedule_order0.cpp)
target_link_libraries(test_schedule_order0 hw1 googletest )
add_test(CorrectOrder_Test0 ./test_schedule_order0)

add_executable(test_schedule_order1 test_schedule_order1.cpp)
target_link_libraries(test_schedule_order1 hw1 googletest )
add_test(CorrectOrder_Test1 ./test_schedule_order1)

add_executable(test_schedule_order2 test_schedule_order2.cpp)
target_link_libraries(test_schedule_order2 hw1 googletest )
add_test(CorrectOrder_Test2 ./test_schedule_order2)

add_executable(test_schedule0 test_schedule0.cpp)
target_link_libraries(test_schedule0 hw1 googletest )
add_test(CorrectSchedule0 ./test_schedule0)

add_executable(test_schedule1 test_schedule1.cpp)
target_link_libraries(test_schedule1 hw1 googletest )
add_test(CorrectSchedule1 ./test_schedule1)

add_executable(test_schedule2 test_schedule2.cpp)
target_link_libraries(test_schedule2 hw1 googletest )
add_test(CorrectSchedule2 ./test_schedule2)

add_executable(test_schedule3 test_schedule3.cpp)
target_link_libraries(test_schedule3 hw1 googletest )
add_test(CorrectSchedule3 ./test_schedule3)

add_executable(test_schedule4 test_schedule4.cpp)
target_link_libraries(test_schedule4 hw1 googletest )
add_test(CorrectSchedule4 ./test_schedule4)





add_executable(test_schedule_rr_order0 test_schedule_rr_order0.cpp)
target_link_libraries(test_schedule_rr_order0 hw1 googletest )
add_test(CorrectOrder_RR_Test0 ./test_schedule_rr_order0)

add_executable(test_schedule_rr_order1 test_schedule_rr_order1.cpp)
target_link_libraries(test_schedule_rr_order1 hw1 googletest )
add_test(CorrectOrder_RR_Test1 ./test_schedule_rr_order1)

add_executable(test_schedule_rr_order2 test_schedule_rr_order2.cpp)
target_link_libraries(test_schedule_rr_order2 hw1 googletest )
add_test(CorrectOrder_RR_Test2 ./test_schedule_rr_order2)


add_executable(test_schedule_round_robin0 test_schedule_rr_order0.cpp)
target_link_libraries(test_schedule_round_robin0 hw1 googletest )
add_test(RoundRobin_Test0 ./test_schedule_round_robin0)

add_executable(test_schedule_round_robin1 test_schedule_rr_order1.cpp)
target_link_libraries(test_schedule_round_robin1 hw1 googletest )
add_test(RoundRobin_Test1 ./test_schedule_round_robin1)

add_executable(test_schedule_round_robin2 test_schedule_rr_order2.cpp)
target_link_libraries(test_schedule_round_robin2 hw1 googletest )
add_test(RoundRobin_Test2 ./test_schedule_round_robin2)


add_executable(test_schedule0_rr test_schedule0_rr.cpp)
target_link_libraries(test_schedule0_rr hw1 googletest )
add_test(CorrectRRSchedule0 ./test_schedule0_rr)

add_executable(test_schedule1_rr test_schedule1_rr.cpp)
target_link_libraries(test_schedule1_rr hw1 googletest )
add_test(CorrectRRSchedule1 ./test_schedule1_rr)

add_executable(test_schedule2_rr test_schedule2_rr.cpp)
target_link_libraries(test_schedule2_rr hw1 googletest )
add_test(CorrectRRSchedule2 ./test_schedule2_rr)

add_executable(test_schedule3_rr test_schedule3_rr.cpp)
target_link_libraries(test_schedule3_rr hw1 googletest )
add_test(CorrectRRSchedule3 ./test_schedule3_rr)

add_executable(test_schedule4_rr test_schedule4_rr.cpp)
target_link_libraries(test_schedule4_rr hw1 googletest )
add_test(CorrectRRSchedule4 ./test_schedule4_rr)



