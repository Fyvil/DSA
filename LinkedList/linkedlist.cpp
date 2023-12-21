#include "./linkedlist.h"
#include <vector>

LinkedList::LinkedList() {
  head = nullptr;
  tail = nullptr;
  len = 0;
}

LinkedList::LinkedList(int x) {
  Node *newNode = new Node(x);
  head = newNode;
  tail = newNode;
  len = 1;
}

LinkedList::LinkedList(int *arr, int arr_len) {
  Node *newNode = new Node(arr[0]);
  head = newNode;
  tail = newNode;
  len = 1;
  for (int i = 1; i < arr_len; i++) {
    newNode = new Node(arr[i]);
    tail->next = newNode;
    tail = newNode;
    len++;
  }
}

LinkedList::LinkedList(const std::vector<int> &vec) {
  Node *newNode = new Node(vec[0]);
  head = newNode;
  tail = newNode;
  len = 1;
  for (int i = 1, n = static_cast<int>(vec.size()); i < n; i++) {
    newNode = new Node(vec[i]);
    tail->next = newNode;
    tail = newNode;
    len++;
  }
}

LinkedList::~LinkedList() {
  while (head != nullptr) {
    Node *d{head};
    head = head->next;
    delete d;
    len--;
  }
  head = nullptr;
  tail = nullptr;
}

void LinkedList::print() const {
  if (len == 0) {
    std::cout << "Empty Linked List. Consider adding elements." << std::endl;
    return;
  }
  Node *temp{head};
  while (temp != nullptr) {
    std::cout << temp->val << " -> ";
    temp = temp->next;
  }
  std::cout << "nullptr" << std::endl;
}

void LinkedList::details() const {
  if (len == 0) {
    std::cout << "Empty List." << std::endl;
  } else {
    std::cout << "Head: " << head->val << "\nTail: " << tail->val
              << "\nLength: " << len << std::endl;
  }
}
