add_executable(labCons commander/Line.cpp table/TableNum.cpp table/TableStr.cpp commander/Add_Command.cpp commander/AddNum_Command.cpp commander/Terminal.cpp main.cpp)

target_link_libraries(labCons
    PRIVATE Lab::lab
)

add_custom_target(cons COMMAND labCons)