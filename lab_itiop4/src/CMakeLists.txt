
add_executable(labCons commander/Line.cpp table/Table.cpp commander/Terminal.cpp main.cpp)

target_link_libraries(labCons
    PRIVATE Lab::lab
) 