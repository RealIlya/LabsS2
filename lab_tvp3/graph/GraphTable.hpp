#ifndef _GRAPH_HPP_
#define _GRAPH_HPP_
#include <math.h>

#include <string>

#include "GraphNode.hpp"

class GraphTable {
 private:
  int _size;
  size_t _fulness;
  GraphNode **_elems;

  int getHash(std::string key, bool h);
  int getIndex(std::string key);
  int getMatrixIndex(GraphNode *gn);
  void calculateMatrix(int **res_matrix, int **matrix1, int **matrix2);
  void check(int *good_graph_nodes, int **matrix);
  GraphNode *getMatrixElem(int index);
  void mark(int *good_graph_nodes);

 public:
  GraphTable(int size);
  ~GraphTable();
  void print();
  GraphNode *add(std::string key, std::string direction);
  void just_do_something(int max_way_size);
};
#endif