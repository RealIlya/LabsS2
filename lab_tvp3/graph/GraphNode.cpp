#include "GraphNode.hpp"

GraphNode::Stack_g::Stack_g() {
  value = nullptr;
  next = nullptr;
  marked = false;
}

GraphNode::GraphNode(std::string key) {
  this->key = key;
  this->gs = new Stack_g();
}

GraphNode::~GraphNode() {
  if (gs) gs->~Stack_g();
  if (gs) delete gs;
  gs = nullptr;
}

void GraphNode::add(GraphNode *direction) {
  if (!gs) gs = new Stack_g();
  if (!gs->contains(direction)) gs->push(direction);
}

void GraphNode::print() {
  std::cout << "Вершина: " << key << std::endl;
  if (gs->next) {
    std::cout << gs->size() << " дуг исходящие из этой " << key
              << " вершины и входящие в вершины: ";
    GraphNode::Stack_g *sg = gs;
    while (sg->next) {
      std::cout << " ";
      if (sg->marked) std::cout << "~";
      std::cout << sg->value->key;
      sg = sg->next;
    }
    std::cout << std::endl;
  } else {
    std::cout << "Нет дуг исходящих из этой вершины" << std::endl;
  }
}

GraphNode::Stack_g::~Stack_g() {
  while (next) {
    GraphNode::Stack_g *sg = next;
    next = next->next;
    delete sg;
    sg = nullptr;
  }
}

void GraphNode::Stack_g::push(GraphNode *value) {
  GraphNode::Stack_g *sg = new GraphNode::Stack_g();
  sg->value = this->value;
  sg->next = next;
  this->value = value;
  next = sg;
}

int GraphNode::Stack_g::size() {
  int n = 0;
  GraphNode::Stack_g *sg = this;
  while (sg->next) {
    sg = sg->next;
    n++;
  }
  return n;
}

bool GraphNode::Stack_g::contains(GraphNode *value) {
  bool result = false;
  GraphNode::Stack_g *sg = this;
  while ((!result) && sg->next) {
    if (value == sg->value) result = true;
    sg = sg->next;
  }
  if (sg->value == value) result = true;
  return result;
}