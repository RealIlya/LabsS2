add_executable(labCons commander/Line.cpp table/Table.cpp table/OrderedTable.cpp commander/Add_Command.cpp commander/AddInOrder_Command.cpp commander/Terminal.cpp main.cpp)

# target_link_libraries(labCons
#     PRIVATE Lab::lab
# )