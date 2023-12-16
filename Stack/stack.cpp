#include "stack.h"

Stack::Stack(int x) {
  std::shared_ptr<Node> n = std::make_shared<Node>(x);
  head = n;
  height = 1;
}

Stack::Stack(const std::vector<int> &vec) {
  if (vec.empty())
    return;
  std::shared_ptr<Node> t{std::make_shared<Node>(vec[0])};
  head = t;
  height = 1;
  for (int i = 1, n = static_cast<int>(vec.size()); i < n; i++) {
    std::shared_ptr<Node> newNode{std::make_shared<Node>(vec[i])};
    t->next = newNode;
    t = newNode;
    height++;
  }
}

Stack::~Stack() {
  while (head != nullptr) {
    std::shared_ptr<Node> t{head};
    head = head->next;
  }
  height = 0;
}

void Stack::print() const {
  if (height == 0) {
    std::cout << "Empty stack. Considering adding nodes using push()."
              << std::endl;
    return;
  }
  std::shared_ptr<Node> t{head};
  for (int i = 0; i < height; i++) {
    std::cout << t->val << "\n|\n";
    t = t->next;
  }
  std::cout << "nullptr\n----------" << std::endl;
}

std::shared_ptr<Node> Stack::getTail() const {
  std::shared_ptr<Node> t{head};
  while (t->next != nullptr) {
    t = t->next;
  }
  return t;
}

void Stack::details() const {
  if (height == 0) {
    std::cout << "Head: NULL"
              << "\nTail: NULL"
              << "\nHeight: 0" << std::endl;
    return;
  }
  std::cout << "Head: " << head->val << "\nTail: " << getTail()->val
            << "\nHeight: " << height << std::endl;
}

// Adds a node to the top of the stack
void Stack::push(int x) {
  std::shared_ptr<Node> n{std::make_shared<Node>(x)};
  std::shared_ptr<Node> t{head};
  head = n;
  head->next = t;
  height++;
}

// Adds a vector of nodes in order to the top of the stack
void Stack::push(const std::vector<int> &vec) {
  for (int i = static_cast<int>(vec.size()) - 1; i >= 0; i--) {
    push(vec[i]);
  }
}

bool Stack::pop() {
  if (height == 0)
    return false;
  if (height == 1) {
    head = nullptr;
  } else {
    head = head->next;
  }
  height--;
  return true;
}

// Pops the first n nodes
bool Stack::pop(int k) {
  if (height == 0)
    return false;
  for (int i = 0; i < k; i++) {
    pop();
  }
  return true;
}

// empties the stack
bool Stack::emptyStack() {
  if (height == 0)
    return false;
  int n{height};
  for (int i = 0; i < n; i++) {
    pop();
  }
  return true;
}
