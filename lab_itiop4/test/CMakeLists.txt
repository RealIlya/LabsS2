# add_executable(labUnitTest commander/Line.cpp test_main.cpp)

add_executable(labUnitTest table/Table.cpp main.cpp)

target_link_libraries(labUnitTest 
    PRIVATE Lab::lab
)

add_custom_target(check ALL COMMAND labUnitTest)