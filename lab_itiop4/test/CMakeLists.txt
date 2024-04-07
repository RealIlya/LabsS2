add_executable(labUnitTest table/Table.cpp table/OrderedTable.cpp main.cpp)

target_link_libraries(labUnitTest 
    PRIVATE Lab::lab
)

add_custom_target(check ALL COMMAND labUnitTest)