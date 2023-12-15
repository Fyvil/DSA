#ifndef DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

struct Node {
  int val;
  Node *next;
  Node *prev;
  explicit Node(int x) : val{x}, next{nullptr}, prev{nullptr} {}
  ~Node() = default;
};

class DoublyLinkedList {
private:
  Node *head;
  Node *tail;
  int length;

public:
  DoublyLinkedList() : head{nullptr}, tail{nullptr}, length{0} {}
  explicit DoublyLinkedList(int x);
  DoublyLinkedList(int *arr, int arr_len);
  explicit DoublyLinkedList(const std::vector<int> &vec);
  ~DoublyLinkedList();

  void print() const;
  void details() const;

  Node *getHead() {
    if (length == 0)
      return nullptr;
    return head;
  }
  Node *getTail() {
    if (length == 0)
      return nullptr;
    return tail;
  }
  int size() { return length; }
  Node *get(int index);

  void prepend(int x);
  void prepend(int *arr, int arr_len);
  void prepend(const std::vector<int> &vec);
  void append(int x);
  void append(int *arr, int arr_len);
  void append(const std::vector<int> &vec);
  void insert(int index, int x);
  void insert(int index, int *arr, int arr_len);
  void insert(int index, const std::vector<int> &vec);

  void deleteFirst();
  void deleteLast();
  void deleteNode(int index);
  // deletes nodes in range from start to end (both inclusive)
  void deleteInRange(int start, int end);
  void deleteAllNodes();
  void deleteFirstKNodes(int k);
  // deletes all duplicates of specifies value if it exists
  void deleteDuplicates(int x);
  // deletes all duplicates
  void set();
  // pops node and returns the node value
  int pop(int index);

  void sort();
  void reverse();

  void concatenate(const DoublyLinkedList &dll);

  static DoublyLinkedList Union(const DoublyLinkedList &dll1,
                                const DoublyLinkedList &dll2);

  static DoublyLinkedList intersection(const DoublyLinkedList &dll1,
                                       const DoublyLinkedList &dll2);

  void rotate(int k);
};

#endif // DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H
