#include "doublylinkedlist.h"
#include <vector>

DoublyLinkedList::DoublyLinkedList() : head{nullptr}, tail{nullptr}, len{0} {}

DoublyLinkedList::DoublyLinkedList(int x) {
  Node *newNode{new Node(x)};
  head = newNode;
  tail = newNode;
  len = 1;
}

DoublyLinkedList::DoublyLinkedList(int *arr, int arr_len)
    : DoublyLinkedList(arr[0]) {
  for (int i = 1; i < arr_len; i++) {
    Node *newNode{new Node(arr[i])};
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
    len++;
  }
}

DoublyLinkedList::DoublyLinkedList(const std::vector<int> &vec)
    : DoublyLinkedList(vec[0]) {
  for (int i = 1, n = (int)vec.size(); i < n; i++) {
    Node *newNode{new Node(vec[i])};
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
    len++;
  }
}

DoublyLinkedList::~DoublyLinkedList() {
  while (head != nullptr) {
    Node *nodeToDelete{head};
    head = head->next;
    len--;
  }
}

void DoublyLinkedList::print() const {
  if (len == 0) {
    std::cout << "Empty list!" << std::endl;
  } else {
    Node *temp{head};
    while (temp) {
      std::cout << temp->val << " <-> ";
      temp = temp->next;
    }
    std::cout << "nullptr" << std::endl;
  }
}

void DoublyLinkedList::details() const {
  if (len == 0) {
    return;
  } else {
    std::cout << "Head: " << head->val << "\nTail: " << tail->val
              << "\nLength: " << len << std::endl;
  }
}

Node *DoublyLinkedList::get(int index) {
  if (index < 0 || index >= len || len == 0) {
    std::cout << "Invalid index!" << std::endl;
    return nullptr;
  }
  Node *temp{head};
  for (int i = 0; i < index; i++) {
    temp = temp->next;
  }
  return temp;
}

Node *DoublyLinkedList::getByValue(int x) {
  Node *temp{head};
  while (temp != nullptr) {
    if (temp->val == x) {
      return temp;
    }
  }
  return nullptr;
}

void DoublyLinkedList::prepend(int x) {
  Node *newNode{new Node(x)};
  if (len == 0) {
    tail = newNode;
  } else {
    newNode->next = head;
    head->prev = newNode;
  }
  head = newNode;
  len++;
}

void DoublyLinkedList::prepend(int *arr, int arr_len) {
  if (arr_len == 0) {
    return;
  }
  for (int i = arr_len - 1; i >= 0; i--) {
    prepend(arr[i]);
  }
}

void DoublyLinkedList::prepend(const std::vector<int> &vec) {
  if (vec.empty()) {
    return;
  }
  int n{(int)vec.size()};
  for (int i = n - 1; i >= 0; i--) {
    prepend(vec[i]);
  }
}

void DoublyLinkedList::append(int x) {
  Node *newNode{new Node(x)};
  if (len == 0) {
    head = newNode;
  } else {
    newNode->prev = tail;
    tail->next = newNode;
  }
  tail = newNode;
  len++;
}

void DoublyLinkedList::append(int *arr, int arr_len) {
  if (arr_len == 0) {
    return;
  }
  for (int i = 0; i < arr_len; i++) {
    append(arr[i]);
  }
}

void DoublyLinkedList::append(const std::vector<int> &vec) {
  if (vec.empty()) {
    return;
  }
  for (const int &num : vec) {
    append(num);
  }
}

void DoublyLinkedList::insert(int index, int x) {
  if (index < 0 || index > len) {
    return;
  }
  if (index == 0) {
    prepend(x);
  } else if (index == len) {
    append(x);
  } else {
    Node *temp{get(index - 1)};
    Node *newNode{new Node(x)};
    newNode->prev = temp;
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    len++;
  }
}

void DoublyLinkedList::insert(int index, int *arr, int arr_len) {
  if (index < 0 || index > len || arr_len == 0) {
    return;
  }
  for (int i = arr_len - 1; i >= 0; i--) {
    insert(index, arr[i]);
  }
}

void DoublyLinkedList::insert(int index, const std::vector<int> &vec) {
  if (index < 0 || index > len || vec.empty()) {
    return;
  }
  int n{(int)vec.size()};
  for (int i = n - 1; i >= 0; i--) {
    insert(index, vec[i]);
  }
}

void DoublyLinkedList::deleteFirst() {
  if (len == 0) {
    return;
  }
  Node *nodeToDelete{head};
  if (len == 1) {
    head = nullptr;
    tail = nullptr;
  } else {
    head = head->next;
    head->prev = nullptr;
  }
  delete nodeToDelete;
  len--;
}

void DoublyLinkedList::deleteLast() {
  if (len == 0) {
    return;
  }
  Node *nodeToDelete{tail};
  if (len == 1) {
    head = nullptr;
  } else {
    tail = tail->prev;
  }
  delete nodeToDelete;
  tail->next = nullptr;
  len--;
}

void DoublyLinkedList::deleteNode(int index) {
  if (len == 0 || index < 0 || index >= len) {
    return;
  }
  if (index == 0) {
    deleteFirst();
  } else if (index == len - 1) {
    deleteLast();
  } else {
    if (len == 1) {
      head = nullptr;
      tail = nullptr;
    } else {
      Node *nodeToDelete{get(index)};
      nodeToDelete->prev->next = nodeToDelete->next;
      nodeToDelete->next->prev = nodeToDelete->prev;
      delete nodeToDelete;
    }
    len--;
  }
}

void DoublyLinkedList::deleteFirstKNodes(int k) {
  if (len < k) {
    return;
  }
  for (int i = 0; i < k; i++) {
    deleteFirst();
  }
}

// slices list from start(inclusive) up till end(non-inclusive)
void DoublyLinkedList::slice(int start, int end) {
  if (start < 0 || end > len || start >= end || len <= 1) {
    return;
  }
  int sliceRange{end - start};
  for (int i = 0; i < sliceRange; i++) {
    deleteNode(start);
  }
}

void DoublyLinkedList::deleteDuplicates(int x) {
  if (len <= 1) {
    return;
  }
  bool xFound{false};
  Node *temp{head};
  int tempIndex{0};
  while (temp->next->next != nullptr) {
    if (temp->val == x) {
      xFound = true;
      break;
    }
    temp = temp->next;
    tempIndex++;
  }
  if (xFound) {
    temp = get(tempIndex + 1);
    while (temp != nullptr) {
      if (temp->val == x) {
        Node *nodeToDelete{temp};
        if (temp == tail) {
          deleteLast();
          return;
        } else {
          Node *nodeToDelete{temp};
          temp->prev->next = temp->next;
          temp->next->prev = temp->prev;
          temp = temp->next;
          delete nodeToDelete;
          len--;
        }
      } else {
        temp = temp->next;
      }
    }
  }
}

// Deletes all duplicate values and makes a set
void DoublyLinkedList::set() {
  Node *temp{head};
  while (temp->next != nullptr) {
    deleteDuplicates(temp->val);
    temp = temp->next;
  }
}

void DoublyLinkedList::swapWithFirst(int index) {
  Node *t1{head}, *t2{get(index)}, *t2Prev{t2->prev}, *t1Next{t1->next},
      *t2Next;
  head = t2;
  if (index != len - 1) {
    t2Next = t2->next;
  }
  head->prev = nullptr;
  head->next = t1Next;
  t1Next->prev = head;
  t2Prev->next = t1;
  t1->prev = t2Prev;
  if (index == len - 1) {
    tail = t1;
    tail->next = nullptr;
  } else {
    t1->next = t2Next;
    t2Next->prev = t1;
  }
}

void DoublyLinkedList::swapWithLast(int index) {
  Node *t1{get(index)}, *t2{tail}, *t1Prev{t1->prev}, *t1Next{t1->next},
      *t2Prev{t2->prev};
  tail = t1;
  t1Prev->next = t2;
  t2->prev = t1Prev;
  t2->next = t1Next;
  t1Next->prev = t2;
  t2Prev->next = t1;
  t1->prev = t2Prev;
  tail->next = nullptr;
}

void DoublyLinkedList::swapAdjacent(int m, int n) {
  Node *t1{get(m)}, *t2{t1->next}, *t2Next, *t1Prev;
  if (m == 0) {
    t2Next = t2->next;
    head = t2;
    head->next = t1;
    head->prev = nullptr;
    t1->prev = head;
    t1->next = t2Next;
    t2Next->prev = t1;
  } else if (n == len - 1) {
    t1Prev = t1->prev;
    tail = t1;
    t1Prev->next = t2;
    t2->prev = t1Prev;
    t2->next = t1;
    t1->prev = t2;
    tail->next = nullptr;
  } else {
    t1Prev = t1->prev;
    t2Next = t2->next;
    t1Prev->next = t2;
    t2->prev = t1Prev;
    t2->next = t1;
    t1->prev = t2;
    t1->next = t2Next;
    t2Next->prev = t1;
  }
}

// swaps nodes at indexes m and n. Swaps the nodes themselves
void DoublyLinkedList::swap(int m, int n) {
  if (m < 0 || m >= len || n < 0 || n >= len || len < 2 || m == n) {
    return;
  }
  int start, end;
  if (m < n) {
    start = m;
    end = n;
  } else {
    start = n;
    end = m;
  }
  if (end - start == 1) {
    swapAdjacent(start, end);
  } else if (start == 0) {
    swapWithFirst(end);
  } else if (end == len - 1) {
    swapWithLast(start);
  } else {
    Node *t1{get(start)}, *t2{get(end)}, *t1Prev{t1->prev}, *t1Next{t1->next},
        *t2Next{t2->next}, *t2Prev{t2->prev};
    t1Prev->next = t2;
    t2->prev = t1Prev;
    t2->next = t1Next;
    t1Next->prev = t2;
    t2Prev->next = t1;
    t1->prev = t2Prev;
    t1->next = t2Next;
    t2Next->prev = t1;
  }
}

void DoublyLinkedList::reverse() {
  Node *temp{head}, *after, *before{nullptr};
  head = tail;
  tail = temp;
  for (int i = 0; i < len; i++) {
    after = temp->next;
    temp->next = before;
    before = temp;
    temp = after;
  }
}
