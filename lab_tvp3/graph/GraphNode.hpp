#ifndef _GRAPHNODE_HPP_
#define _GRAPHNODE_HPP_

#include <iostream>

// #include "Stack/Stack_g.hpp"

struct GraphNode {
  std::string key;
  class Stack_g {
   private:
    GraphNode *value;
    Stack_g *next;

   public:
    Stack_g();
    ~Stack_g();

    // GraphNode *pop();
    void print();
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