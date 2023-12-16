/* Stack implementation using linked list */
#ifndef STACK_STACK_H
#define STACK_STACK_H

#include <iostream>
#include <memory>
#include <vector>

class Node {
public:
  int val;
  std::shared_ptr<Node> next;
  explicit Node(int x) : val{x}, next{nullptr} {}
};

class Stack {
private:
  std::shared_ptr<Node> head;
  int height;

public:
  Stack() : head{nullptr}, height{0} {}
  explicit Stack(int x);
  explicit Stack(const std::vector<int> &vec);
  ~Stack();

  void print() const;
  [[nodiscard]] std::shared_ptr<Node> getTail() const;
  void details() const;

  void push(int x);
  void push(const std::vector<int> &vec);

  bool pop();
  bool pop(int k);
  bool emptyStack();
};

#endif // STACK_STACK_H
