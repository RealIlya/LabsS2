#ifndef _GRAPH_HPP_
#define _GRAPH_HPP_
#include <math.h>

#include <string>

#include "GraphNode.hpp"
// #include "Stack/Stack_g.hpp"
class GraphTable {
 private:
  int _size;
  int _fulness;
  GraphNode **_elems;

  int getHash(std::string key, bool h);
  int getIndex(std::string key);

 public:
  GraphTable(int size);
  ~GraphTable();
  void print();
  GraphNode *add(std::string key, std::string direction);
};

/*
class GraphTree {
 private:
  GraphNode *_root;
  GraphTree *left, *right;
  GraphNode *addNode(std::string key);
 public:
  GraphTree();
  ~GraphTree();
  void add(std::string key, std::string direction);
  void print();
};
*/
#endif