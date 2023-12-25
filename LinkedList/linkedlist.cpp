#include "./linkedlist.h"
#include <cmath>
#include <vector>

LinkedList::LinkedList() {
  head = nullptr;
  tail = nullptr;
  len = 0;
}

LinkedList::LinkedList(int x) {
  Node *newNode{new Node(x)};
  head = newNode;
  tail = newNode;
  len = 1;
}

LinkedList::LinkedList(const int *arr, int arr_len) {
  Node *newNode{new Node(arr[0])};
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
  Node *newNode{new Node(vec[0])};
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

// Copy constructor
LinkedList::LinkedList(const LinkedList &ll) {
  if (ll.len == 0) {
    head = nullptr;
    tail = nullptr;
    len = 0;
    return;
  }
  Node *newNode{new Node(ll.head->val)};
  head = newNode;
  tail = newNode;
  len = 1;
  Node *temp{ll.head->next};
  while (temp != nullptr) {
    append(temp->val);
    temp = temp->next;
  }
  std::cout << "Copy Constructor called" << std::endl;
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

Node *LinkedList::get(int index) {
  if (index < 0 || index >= len) {
    return nullptr;
  }
  Node *temp{head};
  for (int i = 0; i < index; i++) {
    temp = temp->next;
  }
  return temp;
}

void LinkedList::prepend(int x) {
  Node *newNode{new Node(x)};
  if (len == 0) {
    head = newNode;
    tail = newNode;
  } else {
    newNode->next = head;
    head = newNode;
  }
  len++;
}

void LinkedList::prepend(const int *arr, const int &arr_len) {
  if (arr_len == 0) {
    return;
  } else {
    for (int i = arr_len - 1; i >= 0; i--) {
      prepend(arr[i]);
    }
  }
}

void LinkedList::prepend(const std::vector<int> &vec) {
  for (int i = static_cast<int>(vec.size()) - 1; i >= 0; i--) {
    prepend(vec[i]);
  }
}

void LinkedList::append(int x) {
  Node *newNode{new Node(x)};
  if (len == 0) {
    head = newNode;
    tail = newNode;
  } else {
    tail->next = newNode;
    tail = newNode;
  }
  len++;
}

void LinkedList::append(const int *arr, int arr_len) {
  if (arr_len == 0) {
    return;
  } else {
    for (int i = 0; i < arr_len; i++) {
      append(arr[i]);
    }
  }
}

void LinkedList::append(const std::vector<int> &vec) {
  for (const int &num : vec) {
    append(num);
  }
}

void LinkedList::insert(int index, int x) {
  if (index < 0 || index > len) {
    return;
  }
  if (index == 0) {
    prepend(x);
  } else if (index == len) {
    append(x);
  } else {
    Node *temp{head};
    for (int i = 0, n = index - 1; i < n; i++) {
      temp = temp->next;
    }
    Node *newNode{new Node(x)};
    newNode->next = temp->next;
    temp->next = newNode;
    len++;
  }
}

void LinkedList::insert(int index, const int *arr, const int &arr_len) {
  if (arr_len == 0 || index < 0 || index > len) {
    return;
  }
  for (int i = 0; i < arr_len; i++) {
    insert(index, arr[i]);
    index++;
  }
}

void LinkedList::insert(int index, const std::vector<int> &vec) {
  if (index < 0 || index > len) {
    return;
  }
  for (const int &num : vec) {
    insert(index, num);
    index++;
  }
}

void LinkedList::deleteFirst() {
  if (len == 0) {
    return;
  }
  Node *nodeToDelete{head};
  head = head->next;
  delete nodeToDelete;
  len--;
}

void LinkedList::deleteLast() {
  if (len == 0) {
    return;
  }
  Node *nodeToDelete{tail};
  Node *temp{head};
  while (temp->next != tail && temp != tail) {
    temp = temp->next;
  }
  temp->next = nullptr;
  tail = temp;
  delete nodeToDelete;
  len--;
}

void LinkedList::deleteByIndex(int index) {
  if (len == 0 || index < 0 || index >= len) {
    return;
  }
  if (index == 0) {
    deleteFirst();
  } else if (index == len - 1) {
    deleteLast();
  } else {
    Node *prev{head};
    for (int i = 0, n = index - 1; i < n; i++) {
      prev = prev->next;
    }
    Node *nodeToDelete{prev->next};
    prev->next = nodeToDelete->next;
    delete nodeToDelete;
    len--;
  }
}

// Deletes first occurrence of value if it exists
void LinkedList::deleteByValue(int x) {
  if (len == 0) {
    return;
  }
  if (head->val == x) {
    deleteFirst();
  } else {
    Node *temp{head};
    while (temp != nullptr) {
      if (temp->next->val == x) {
        if (temp->next == tail) {
          deleteLast();
        } else {
          Node *nodeToDelete{temp->next};
          temp->next = nodeToDelete->next;
          delete nodeToDelete;
          len--;
        }
        return;
      }
      temp = temp->next;
    }
  }
}

// Slice in range from start (inclusive) up till end (non-inclusive)
void LinkedList::slice(int start, int end) {
  if (len <= 1 || start >= end || start < 0 || end > len) {
    return;
  }
  for (int i = 0, n = end - start; i < n; i++) {
    deleteByIndex(start);
  }
}

void LinkedList::makeEmpty() { slice(0, size()); }

// Deletes all duplicates of a value if it exists
void LinkedList::deleteDuplicates(int x) {
  if (len <= 1) {
    return;
  }
  bool x_found{false};
  Node *temp{head};
  while (temp != nullptr) {
    if (temp->val == x) {
      x_found = true;
      break;
    }
    temp = temp->next;
  }
  if (x_found) {
    while (temp != nullptr && temp->next != nullptr) {
      if (temp->next->val == x) {
        if (temp->next == tail) {
          deleteLast();
        } else {
          Node *nodeToDelete{temp->next};
          temp->next = nodeToDelete->next;
          delete nodeToDelete;
          len--;
          continue;
        }
      }
      temp = temp->next;
    }
  }
}

void LinkedList::set() {
  Node *temp{head};
  while (temp != nullptr) {
    deleteDuplicates(temp->val);
    temp = temp->next;
  }
}

// naive bubble sort
void LinkedList::bubbleSort() {
  if (len <= 1) {
    return;
  }
  int swapCounter{-1};
  while (swapCounter != 0) {
    Node *temp{head};
    swapCounter = 0;
    for (int i = 0, n = len - 1; i < n; i++) {
      if (temp->val > temp->next->val) {
        int t{temp->next->val};
        temp->next->val = temp->val;
        temp->val = t;
        swapCounter++;
      }
      temp = temp->next;
    }
  }
}

// reverses linked list in place
void LinkedList::reverse() {
  if (len <= 1) {
    return;
  }
  Node *temp{head};
  head = tail;
  tail = temp;
  Node *after;
  Node *before{nullptr};
  for (int i = 0; i < len; i++) {
    after = temp->next;
    temp->next = before;
    before = temp;
    temp = after;
  }
}

// Reverses sublist from start(inclusive) up till end(inclusive)
void LinkedList::reverseSublist(int start, int end) {
  if (len <= 1 || start >= end || start < 0 || end >= len) {
    return;
  }
  Node *tempHead{head};
  Node *tempTail{head};
  Node *after;
  Node *before;
  Node *temp;
  Node *t;
  int range{end - start};
  Node *dummy{new Node(0)};
  Node *dummy2{new Node(0)};
  if (start == 0 && end == len - 1) {
    reverse();
    return;
  } else if (start == 0 && end != len - 1) {
    for (int i = 0; i < range; i++) {
      tempTail = tempTail->next;
    }
    head = tempTail;
    temp = tempHead;
    before = nullptr;
    dummy->next = tempTail->next;
  } else if (start != 0 && end == len - 1) {
    tempTail = tail;
    for (int i = 0; i < start - 1; i++) {
      tempHead = tempHead->next;
    }
    before = tempHead;
    temp = tempHead;
    tempHead = tempHead->next;
    tail = tempHead;
    dummy->next = tempTail;
  } else {
    for (int i = 0; i < start - 1; i++) {
      tempHead = tempHead->next;
    }
    before = tempHead;
    temp = tempHead;
    tempHead = tempHead->next;
    tempTail = tempHead;
    t = tempHead;
    for (int i = 0; i < range; i++) {
      tempTail = tempTail->next;
    }
    dummy->next = tempTail;
    dummy2->next = tempTail->next;
  }
  for (int i = 0; i <= range; i++) {
    after = tempHead->next;
    tempHead->next = before;
    before = tempHead;
    tempHead = after;
  }
  temp->next = dummy->next;
  delete dummy;
  if (start != 0 && end != len - 1) {
    t->next = dummy2->next;
  }
  delete dummy2;
  tail->next = nullptr;
}

void LinkedList::concatenate(const LinkedList &ll) {
  Node *temp{ll.head};
  while (temp != nullptr) {
    append(temp->val);
    temp = temp->next;
  }
}

// Adds the 2 linked lists (Eg: LL with nodes 12345 and another LL with nodes
// 123 will be (12345 + 123) = 12468 -> This will represent the modified LL)
LinkedList &LinkedList::operator+=(const LinkedList &ll) {
  int num1{0};
  int mult{len - 1};
  Node *temp{head};
  while (temp != nullptr) {
    num1 += temp->val * static_cast<int>(std::pow(10, mult));
    mult--;
    temp = temp->next;
  }
  makeEmpty();
  int num2{0};
  mult = ll.len - 1;
  temp = ll.head;
  while (temp != nullptr) {
    num2 += temp->val * static_cast<int>(std::pow(10, mult));
    mult--;
    temp = temp->next;
  }
  long sum{num1 + num2};
  int numDigits{0};
  long t{sum};
  while (t > 0) {
    numDigits++;
    t /= 10;
  }
  for (int i = 0; i < numDigits; i++) {
    prepend(sum % 10);
    sum /= 10;
  }
  return *this;
}

// Multiplies digits of LL1 with LL2 and modified LL1 accordingly
LinkedList &LinkedList::operator*=(const LinkedList &ll) {
  int num1{0};
  int mult{len - 1};
  Node *temp{head};
  while (temp != nullptr) {
    num1 += temp->val * static_cast<int>(std::pow(10, mult));
    mult--;
    temp = temp->next;
  }
  makeEmpty();
  int num2{0};
  mult = ll.len - 1;
  temp = ll.head;
  while (temp != nullptr) {
    num2 += temp->val * static_cast<int>(std::pow(10, mult));
    mult--;
    temp = temp->next;
  }
  long product{num1 * num2};
  std::cout << product << std::endl;
  long t{product};
  int numDigits{0};
  while (t > 0) {
    numDigits++;
    t /= 10;
  }
  for (int i = 0; i < numDigits; i++) {
    prepend(product % 10);
    product /= 10;
  }
  return *this;
}

// Finds the union of 2 linked lists and returns a new sorted linked list(no
// duplicates)
LinkedList LinkedList::Union(const LinkedList &ll1, const LinkedList &ll2) {
  LinkedList newLinkedList{};
  newLinkedList.concatenate(ll1);
  newLinkedList.concatenate(ll2);
  newLinkedList.set();
  newLinkedList.bubbleSort();
  return newLinkedList;
}

// Finds the intersection of 2 linked lists and returns a new sorted linked list
// (no duplicates)
LinkedList LinkedList::Intersection(const LinkedList &ll1,
                                    const LinkedList &ll2) {
  LinkedList newLinkedList{};
  if (ll1.len == 0 && ll2.len == 0) {
    return newLinkedList;
  }
  Node *t1;
  Node *t2;
  if (ll1.len >= ll2.len) {
    t1 = ll1.head;
    t2 = ll2.head;
  } else {
    t1 = ll2.head;
    t2 = ll1.head;
  }
  while (t2 != nullptr) {
    Node *t{t1};
    bool unionFound{false};
    while (t != nullptr) {
      if (t2->val == t->val) {
        newLinkedList.append(t2->val);
        break;
      }
      t = t->next;
    }
    t2 = t2->next;
  }
  newLinkedList.set();
  newLinkedList.bubbleSort();
  return newLinkedList;
}

// Swaps two nodes by index (swaps the nodes themselves, not the values)
void LinkedList::swap(int m, int n) {
  if (m < 0 || m >= len || n < 0 || n >= len || m == n) {
    return;
  }
  int lowerIndex, higherIndex;
  if (m < n) {
    lowerIndex = m;
    higherIndex = n;
  } else {
    lowerIndex = n;
    higherIndex = m;
  }
  Node *lower{get(lowerIndex)}, *higher{get(higherIndex)}, *lowerPrev,
      *higherPrev{get(higherIndex - 1)}, *lowerNext{get(lowerIndex + 1)},
      *higherNext{get(higherIndex + 1)};
  if (higherIndex == len - 1) {
    tail = lower;
  }
  // If the lower indexed node to be swapped is pointing to the head
  if (lowerIndex == 0) {
    head = higher;
    lower->next = higherNext;
    // If adjacent at head
    if (higherIndex - lowerIndex == 1) {
      higher->next = lower;
    } else {
      higherPrev->next = lower;
      higher->next = lowerNext;
    }
  } else {
    lowerPrev = get(lowerIndex - 1);
    // if adjacent
    if (higherIndex - lowerIndex == 1) {
      lowerPrev->next = higher;
      higher->next = lower;
      lower->next = higherNext;
    } else {
      lowerPrev->next = higher;
      higher->next = lowerNext;
      higherPrev->next = lower;
      lower->next = higherNext;
      tail->next = nullptr;
    }
  }
}

void LinkedList::swapValues(int m, int n) {
  if (m < 0 || n < 0 || m >= len || n >= len || m == n) {
    return;
  }
  int temp{get(m)->val};
  get(m)->val = get(n)->val;
  get(n)->val = temp;
}

// takes a sorted linked list and merges it into the current linked list. Sorted
// in ascending order
void LinkedList::merge(const LinkedList &ll) {
  if (ll.len == 0) {
    return;
  }
  Node *t2{ll.head};
  for (int i = 0; i < ll.len; i++) {
    Node *t1{head};
    int t1pos{0};
    while (t1 != nullptr) {
      if (t2->val <= t1->val) {
        insert(t1pos, t2->val);
        break;
      } else {
        t1 = t1->next;
        t1pos++;
      }
    }
    t2 = t2->next;
  }
}

// Returns a new merged linked list by merging 2 other linked lists
LinkedList LinkedList::merge(const LinkedList &ll1, const LinkedList &ll2) {
  if (ll1.len == 0 & ll2.len != 0) {
    return ll2;
  }
  if (ll1.len != 0 && ll2.len == 0) {
    return ll1;
  }
  LinkedList newLinkedList{};
  if (ll1.len == 0 && ll2.len == 0) {
    return newLinkedList;
  }
  newLinkedList = ll1;
  newLinkedList.merge(ll2);
  return newLinkedList;
}
