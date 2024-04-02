add_executable(labCons commander/Add_Command.cpp commander/Line.cpp table/Table.cpp commander/Terminal.cpp main.cpp)

target_link_libraries(labCons
    PRIVATE Lab::lab
) 

add_custom_target(cons ALL COMMAND labCons)