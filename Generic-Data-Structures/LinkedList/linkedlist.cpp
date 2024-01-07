#ifndef LINKED_LIST
#define LINKED_LIST

#include <cstddef>
#include <iostream>
#include <vector>

/* A Node is an abstract data structure which represents a location in memory
 that holds data of type T and a pointer to the next Node */
template <typename T> struct Node {
  T val;
  Node<T> *next;
  explicit Node(T val) : val{val}, next{nullptr} {}
  ~Node<T>() = default;
};

/* A Linked List (or singly linked list) is a data structure comprised of Nodes,
 each pointing to the next. The final node will point to NULL */
template <typename T> class LinkedList {
private:
  Node<T> *head;
  Node<T> *tail;
  size_t len;

public:
  // Constructors and destructor

  LinkedList<T>() : head{nullptr}, tail{nullptr}, len{0} {}

  LinkedList<T>(T x) {
    Node<T> *newNode{new Node<T>(x)};
    head = newNode;
    tail = newNode;
    len++;
  }

  LinkedList<T>(T *arr, size_t arr_len) : LinkedList(arr[0]) {
    for (size_t i = 1; i < arr_len; i++) {
      Node<T> *newNode{new Node<T>(arr[i])};
      tail->next = newNode;
      tail = newNode;
      len++;
    }
  }

  explicit LinkedList<T>(const std::vector<T> &vec) : LinkedList(vec[0]) {
    len = 1;
    for (size_t i = 1, n = vec.size(); i < n; i++) {
      Node<T> *newNode{new Node<T>(vec[i])};
      tail->next = newNode;
      tail = newNode;
      len++;
    }
  }

  // Copy Constructor
  LinkedList<T>(const LinkedList<T> &sll) {
    if (sll.len == 0) {
      head = nullptr;
      tail = nullptr;
      len = 0;
      return;
    }
    Node<T> *newNode{new Node<T>(sll.head->val)};
    head = newNode;
    tail = newNode;
    len = 1;
    Node<T> *temp{sll.head->next};
    while (temp) {
      append(temp->val);
      temp = temp->next;
    }
  }

  ~LinkedList() {
    while (head) {
      Node<T> *nodeToDelete{head};
      head = head->next;
      delete nodeToDelete;
    }
  }

  Node<T> *get_head() const { return head; }

  Node<T> *get_tail() const { return tail; }

  size_t size() const { return len; }

  // prints the linked list to console
  void print() const {
    if (len == 0) {
      std::cout << "Empty list" << std::endl;
    } else {
      Node<T> *temp{head};
      while (temp) {
        std::cout << temp->val << " -> ";
        temp = temp->next;
      }
      std::cout << "nullptr" << std::endl;
    }
  }

  // prints details of the linked list
  void details() const {
    if (len == 0) {
      std::cout << "Empty Linked List." << std::endl;
    } else {
      std::cout << "Head: " << head->val << "\nTail: " << tail->val
                << "\nLength: " << len << std::endl;
    }
  }

  // Adds a node to the front of the linked list (head)
  void prepend(T x) {
    Node<T> *newNode{new Node<T>(x)};
    if (len == 0) {
      head = newNode;
      tail = newNode;
    } else {
      newNode->next = head;
      head = newNode;
    }
    len++;
  }

  // Adds arr_len Nodes to the front
  void prepend(const T *arr, size_t arr_len) {
    if (arr_len == 0) {
      return;
    }
    for (size_t i = arr_len; i > 0; i--) {
      prepend(arr[i - 1]);
    }
  }

  void prepend(const std::vector<T> &vec) {
    if (vec.empty()) {
      return;
    }
    for (size_t i = vec.size(); i > 0; i--) {
      prepend(vec[i - 1]);
    }
  }

  // Adds a node to the end of the linked list (tail)
  void append(T x) {
    Node<T> *newNode{new Node<T>(x)};
    if (len == 0) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
    len++;
  }

  void append(const T *arr, size_t arr_len) {
    if (arr_len == 0) {
      return;
    }
    for (size_t i = 0; i < arr_len; i++) {
      append(arr[i]);
    }
  }

  void append(const std::vector<T> &vec) {
    if (vec.empty()) {
      return;
    }
    for (const T &val : vec) {
      append(val);
    }
  }

  Node<T> *get(const size_t index) {
    if (len == 0 || index < 0 || index >= len) {
      std::cerr << "Invalid index / empty list error" << std::endl;
      return nullptr;
    }
    Node<T> *temp{head};
    for (size_t i = 0; i < index; i++) {
      temp = temp->next;
    }
    return temp;
  }

  // Inserts node at specified index
  void insert(const size_t index, T x) {
    if (index < 0 || index > len) {
      return;
    }
    if (index == 0) {
      prepend(x);
    } else if (index == len) {
      append(x);
    } else {
      Node<T> *prevNode{get(index - 1)};
      Node<T> *newNode{new Node<T>(x)};
      newNode->next = prevNode->next;
      prevNode->next = newNode;
      len++;
    }
  }

  void insert(const size_t index, const T *arr, size_t arr_len) {
    size_t tempIndex{index};
    for (size_t i = 0; i < arr_len; i++) {
      insert(tempIndex, arr[i]);
      tempIndex++;
    }
  }

  void insert(const size_t index, const std::vector<T> &vec) {
    size_t tempIndex{index};
    for (const T &val : vec) {
      insert(tempIndex, val);
      tempIndex++;
    }
  }

  // deletes first node
  void delete_first() {
    if (len == 0) {
      return;
    }
    Node<T> *nodeToDelete{head};
    if (len == 1) {
      head = nullptr;
      tail = nullptr;
    } else {
      head = head->next;
    }
    delete nodeToDelete;
    len--;
  }

  // deletes last node
  void delete_last() {
    if (len == 0) {
      return;
    }
    if (len == 1) {
      delete_first();
    } else {
      Node<T> *nodeToDelete{tail};
      // accessing second lasdt node
      tail = get(len - 2);
      tail->next = nullptr;
      delete nodeToDelete;
      len--;
    }
  }

  void delete_node(const size_t index) {
    if (index < 0 || index >= len || len == 0) {
      return;
    }
    if (index == 0) {
      delete_first();
    } else if (index == len - 1) {
      delete_last();
    } else {
      Node<T> *nodeToDelete{get(index)}, *prevNode{get(index - 1)};
      prevNode->next = nodeToDelete->next;
      delete nodeToDelete;
      len--;
    }
  }

  // Pops a node by index and returns the value
  T pop(const size_t index) {
    T val{get(index)->val};
    delete_node(index);
    return val;
  }

  // slices list from start(inclusive) to end (non-inclusive)
  void slice(const size_t start, const size_t end) {
    if (len <= 1 || start < 0 || end > len || start >= end) {
      return;
    }
    for (size_t i = 0, n = end - start; i < n; i++) {
      delete_node(start);
    }
  }

  // reverses the linked list in place
  void reverse() {
    if (len <= 1) {
      return;
    }
    Node<T> *temp{head}, *after, *before{nullptr};
    head = tail;
    tail = temp;
    for (size_t i = 0; i < len; i++) {
      after = temp->next;
      temp->next = before;
      before = temp;
      temp = after;
    }
  }

  // reverses sublist of list in place
  void reverse_sublist(const int m, const int n);

  void swap(const int m, const int n);

  void concatenate(const LinkedList<T> *sll) {
    Node<T> *temp{sll->head};
    while (temp) {
      append(temp->val);
      temp = temp->next;
    }
  }
  void concatenate(const LinkedList<T> &sll) {
    Node<T> *temp{sll.head};
    while (temp) {
      append(temp->val);
      temp = temp->next;
    }
  }
};

#endif // !LINKED_LIST
