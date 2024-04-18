#include "defend.hpp"

#include <string.h>

#include <iostream>

#include "graph/GraphTable.hpp"

void getStr(char *container) {
  std::string str;
  std::cin >> str;
  int len = str.length();
  for (int i = 0; i < STR_BUFFER; i++) {
    container[i] = (i < len) ? str[i] : 0;
  }
}

int main() {  // int argv, char **args) {
  // int max_way_size = (argv == 2) ? std::stoi(args[1]) : MAX_WAY_SIZE;
  char command[STR_BUFFER];
  for (int i = 0; i < STR_BUFFER; i++) command[i] = 0;
  GraphTable *graph_table = new GraphTable(STR_BUFFER);
  getStr(command);
  while (strcmp(command, "exit") != 0) {
    if (strcmp(command, "add") == 0) {
      std::string graph_node, direction;
      std::cin >> graph_node;
      getStr(command);
      if (strcmp(command, "->") == 0) {
        std::cin >> direction;
        graph_table->add(graph_node, direction);
      } else {
        graph_table->add(graph_node, direction);
        continue;
      }
    } else if (strcmp(command, "print") == 0) {
      graph_table->print();
    }
    getStr(command);
  }
  return 0;
}