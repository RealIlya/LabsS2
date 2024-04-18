#include "GraphTable.hpp"

GraphTable::GraphTable(int size) : _size{size}, _fulness{0} {
  _elems = new GraphNode *[size];
  for (int i = 0; i < _size; i++) _elems[i] = nullptr;
}

GraphTable::~GraphTable() {
  delete[] _elems;
  _elems = nullptr;
}

int GraphTable::getHash(std::string key, bool h) {
  int hash = 0;
  for (size_t i = 0; i < key.size(); i++)
    hash = (hash << 5) - hash + int(pow(-1, h)) * key[i];

  return abs(hash);
}

int GraphTable::getIndex(std::string key) { return getHash(key, 0) % _size; }

GraphNode *GraphTable::add(std::string key, std::string direction) {
  int index = getIndex(key);

  for (int i = 0; i < _size; i++) {
    if (!_elems[index]) {
      _elems[index] = new GraphNode(key);
      _fulness++;
      if (!direction.empty()) _elems[index]->add(add(direction, ""));
      return _elems[index];
    } else if (key == _elems[index]->key) {
      if (!direction.empty()) _elems[index]->add(add(direction, ""));
      return _elems[index];
    }

    index = (getHash(key, 0) + i * getHash(key, 1)) % _size;
  }

  return nullptr;
}

void GraphTable::print() {
  for (int i = 0; i < _size; i++) {
    if (_elems[i]) _elems[i]->print();
  }
}

int GraphTable::getMatrixIndex(GraphNode *gn) {
  int result = 0;
  for (int i = 0; i < _size; i++) {
    if (_elems[i]) {
      if (_elems[i] == gn) return result;
      result++;
    }
  }
  return result;
}

GraphNode *GraphTable::getMatrixElem(int index) {
  int j = 0;
  GraphNode *res = nullptr;
  for (int i = 0; i < _size; i++) {
    if (_elems[i]) {
      if (index == j)
        res = _elems[i];
      else
        j++;
    }
  }
  return res;
}

void GraphTable::just_do_something(int max_way_size) {
  int **matrix = new int *[_fulness], **start_matrix = new int *[_fulness],
      **buf_matrix = new int *[_fulness];
  int *good_graph_nodes = new int[_fulness];
  for (size_t i = 0; i < _fulness; i++) {
    good_graph_nodes[i] = 0;
    matrix[i] = new int[_fulness];
    start_matrix[i] = new int[_fulness];
    buf_matrix[i] = new int[_fulness];
    for (size_t j = 0; j < _fulness; j++) {
      matrix[i][j] = 0;
      start_matrix[i][j] = 0;
      buf_matrix[i][j] = 0;
    }
  }
  int mi = 0, mj = 0;
  for (int i = 0; i < _size; i++) {
    if (_elems[i]) {
      mi = getMatrixIndex(_elems[i]);
      GraphNode::Stack_g *buf = _elems[i]->gs;
      while (buf->next) {
        mj = getMatrixIndex(buf->value);
        matrix[mi][mj] = 1;
        start_matrix[mi][mj] = 1;
        buf_matrix[mi][mj] = 1;
        buf = buf->next;
      }
    }
  }
  check(good_graph_nodes, matrix);
  for (int i = 0; i < max_way_size; i++) {
    calculateMatrix(matrix, start_matrix, buf_matrix);
    check(good_graph_nodes, matrix);
    for (size_t j = 0; j < _fulness; j++)
      for (size_t k = 0; k < _fulness; k++) buf_matrix[j][k] = matrix[j][k];
  }
  mark(good_graph_nodes);
  for (size_t i = 0; i < _fulness; i++) {
    delete[] matrix[i];
    delete[] start_matrix[i];
    delete[] buf_matrix[i];
  }
  delete[] matrix;
  delete[] start_matrix;
  delete[] buf_matrix;
}

void GraphTable::calculateMatrix(int **res_matrix, int **matrix1,
                                 int **matrix2) {
  for (size_t i = 0; i < _fulness; i++) {
    for (size_t j = 0; j < _fulness; j++) {
      for (size_t k = 0; k < _fulness; k++) {
        res_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
      }
      res_matrix[i][j] = (res_matrix[i][j] > 0) ? 1 : 0;
    }
  }
}

void GraphTable::check(int *good_graph_nodes, int **matrix) {
  for (size_t i = 0; i < _fulness; i++)
    if (matrix[i][i]) good_graph_nodes[i] = 1;
}

void GraphTable::mark(int *good_graph_nodes) {
  for (int i = 0; i < _size; i++) {
    if (_elems[i]) {
      GraphNode::Stack_g *buf = _elems[i]->gs;
      while (buf->next) {
        if (good_graph_nodes[getMatrixIndex(buf->value)]) buf->marked = true;
        buf = buf->next;
      }
    }
  }
}
