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

/*#include "GraphTree.hpp"

GraphTree::GraphTree() : _root{nullptr}, left{nullptr}, right{nullptr} {}

GraphTree::~GraphTree() {
  _root->~GraphNode();
  delete _root;
  _root = nullptr;
}

void *GraphTree::add(std::string key, std::string direction) {
  if (!_root) {
    _root = new GraphNode(key);
    if (!direction.empty()) _root->add(direction);
  } else {
    GraphTree *cur = this;
    GraphTree *buff = cur;
    while (cur) {
      buff = cur;
      if (key != cur->_root->key) {
        cur = key > cur->_root->key ? cur->left : cur->right;
      } else
        break;
    }
    if (key == buff->_root->key) {
      if (!direction.empty()) {
        buff->_root->add(direction);
      }
    } else {
      GraphNode *node = new GraphNode(key);
      if (!direction.empty()) node->add(direction);
      if (key > buff->_root->key) {
        buff->left = new GraphTree();
        buff->left->_root = node;
      } else {
        buff->right = new GraphTree();
        buff->right->_root = node;
      }
    }
  }
}

void GraphTree::print() {
  if (_root) {
    GraphTree *cur = this;
    while (cur) {
      _root->print();
      if (cur->left) cur->left->print();
      if (cur->right) cur->right->print();
    }
  }
}*/