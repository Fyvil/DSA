#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <cmath>
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
  static void mergeSubArrays(int *arr, int leftIndex, int midIndex,
                             int rightIndex);
  static void mergeSort(int *arr, int leftIndex, int rightIndex);

public:
  LinkedList();
  LinkedList(int x);
  LinkedList(const int *arr, int arr_len);
  LinkedList(const std::vector<int> &vec);
  LinkedList(const LinkedList &ll);
  ~LinkedList();

  void print() const;
  void details() const;
  int size() const { return len; }
  Node *get(int index);
  Node *getHead() { return head; }
  Node *getTail() { return tail; }

  void prepend(int x);
  void prepend(const int *arr, const int &arr_len);
  void prepend(const std::vector<int> &vec);
  void append(int x);
  void append(const int *arr, int arr_len);
  void append(const std::vector<int> &vec);
  void insert(int index, int x);
  void insert(int index, const int *arr, const int &arr_len);
  void insert(int index, const std::vector<int> &vec);

  void deleteFirst();
  void deleteLast();
  void deleteByIndex(int index);
  void deleteByValue(int x);

  void slice(int start, int end);
  void makeEmpty();

  void deleteDuplicates(int x);
  void set();

  void bubbleSort();
  void sort();

  void reverse();
  void reverseSublist(int start, int end);
  void concatenate(const LinkedList &ll);

  LinkedList &operator+=(const LinkedList &ll);
  LinkedList &operator*=(const LinkedList &ll);

  static LinkedList Union(const LinkedList &ll1, const LinkedList &ll2);
  static LinkedList Intersection(const LinkedList &ll1, const LinkedList &ll2);

  void swap(int m, int n);
  void swapValues(int m, int n);

  void merge(const LinkedList &ll);
  static LinkedList merge(const LinkedList &ll1, const LinkedList &ll2);
};

#endif // !LINKEDLIST_H
