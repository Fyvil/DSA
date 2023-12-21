#include "./linkedlist.h"
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
