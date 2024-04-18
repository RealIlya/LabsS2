#ifndef _GRAPHNODE_HPP_
#define _GRAPHNODE_HPP_

#include <iostream>

struct GraphNode {
  std::string key;
  class Stack_g {
   public:
    Stack_g();
    ~Stack_g();
    GraphNode *value;
    Stack_g *next;
    bool marked;
    bool contains(GraphNode *value);
    void push(GraphNode *value);
    int size();
  };
  Stack_g *gs;
  GraphNode(std::string key);
  void add(GraphNode *direction);
  void print();
  ~GraphNode();
} typedef GraphNode;

#endif