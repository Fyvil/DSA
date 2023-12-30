#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
#include <vector>

struct Node {
  int val;
  Node *next;
  Node *prev;
  Node(int x) : val{x}, next{nullptr}, prev{nullptr} {}
  ~Node() = default;
};

class DoublyLinkedList {
private:
  Node *head;
  Node *tail;
  int len;
  void swapWithFirst(int index);
  void swapWithLast(int index);
  void swapAdjacent(int m, int n);
  void mergeSubArrays(int *arr, int leftIndex, int midIndex, int rightIndex);
  void mergeSort(int *arr, int leftIndex, int RightIndex);

public:
  DoublyLinkedList();
  DoublyLinkedList(int x);
  DoublyLinkedList(int *arr, int arr_len);
  DoublyLinkedList(const std::vector<int> &vec);
  ~DoublyLinkedList();

  void print() const;
  void details() const;
  Node *get(int index);
  Node *getByValue(int x);
  Node *getHead() const { return head; }
  Node *getTail() const { return tail; }
  int getLength() const { return len; }

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
  void deleteFirstKNodes(int k);
  void slice(int start, int end);
  void deleteDuplicates(int x);
  void set();

  void swap(int m, int n);
  void reverse();
  void bubbleSort();
  void sort();
};

#endif // !DOUBLYLINKEDLIST_H
