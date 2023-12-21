#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <vector>

struct Node {
  int val;
  Node *next;
  Node(int x) : val{x}, next{nullptr} {}
  ~Node() = default;
};

class LinkedList {
private:
  Node *head;
  Node *tail;
  int len;

public:
  LinkedList();
  LinkedList(int x);
  LinkedList(int *arr, int arr_len);
  LinkedList(const std::vector<int> &vec);
  ~LinkedList();

  void print() const;
  void details() const;
};

#endif // !LINKEDLIST_H
