#include "doublylinkedlist.h"

DoublyLinkedList::DoublyLinkedList(int x) {
  Node *newNode{new Node(x)};
  head = newNode;
  tail = newNode;
  length = 1;
}

DoublyLinkedList::DoublyLinkedList(int *arr, int arr_len) {
  Node *newNode{new Node(arr[0])};
  head = newNode;
  tail = newNode;
  length = 1;
  for (int i = 1; i < arr_len; i++) {
    newNode = new Node(arr[i]);
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
    length++;
  }
}

DoublyLinkedList::DoublyLinkedList(const std::vector<int> &vec) {
  Node *newNode{new Node(vec[0])};
  head = newNode;
  tail = newNode;
  length = 1;
  for (int i = 1, n = static_cast<int>(vec.size()); i < n; i++) {
    newNode = new Node(vec[i]);
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
    length++;
  }
}

DoublyLinkedList::~DoublyLinkedList() {
  while (head != nullptr) {
    Node *temp{head};
    head = head->next;
    delete temp;
    length--;
  }
}

void DoublyLinkedList::print() const {
  if (length == 0) {
    std::cout << "Empty List. Consider adding elements." << std::endl;
  } else {
    Node *temp{head};
    while (temp != nullptr) {
      std::cout << temp->val << " <-> ";
      temp = temp->next;
    }
    std::cout << "nullptr" << std::endl;
  }
}

void DoublyLinkedList::details() const {
  if (length == 0) {
    std::cout << "Empty" << std::endl;
  } else {
    std::cout << "Head: " << head->val << "\nTail: " << tail->val
              << "\nLength: " << length << std::endl;
  }
}

Node *DoublyLinkedList::get(int index) {
  if (length == 0 || index < 0 || index >= length)
    return nullptr;
  if (index == 0) {
    return getHead();
  } else if (index == length - 1) {
    return getTail();
  } else {
    Node *temp{head};
    for (int i = 0; i < index; i++) {
      temp = temp->next;
    }
    return temp;
  }
}

void DoublyLinkedList::prepend(int x) {
  Node *newNode{new Node(x)};
  if (length == 0) {
    head = newNode;
    tail = newNode;
    length = 1;
  } else {
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
    length++;
  }
}

void DoublyLinkedList::prepend(int *arr, int arr_len) {
  for (int i = arr_len - 1; i >= 0; i--) {
    prepend(arr[i]);
  }
}

void DoublyLinkedList::prepend(const std::vector<int> &vec) {
  for (int i = static_cast<int>(vec.size()) - 1; i >= 0; i--) {
    prepend(vec[i]);
  }
}

void DoublyLinkedList::append(int x) {
  Node *newNode{new Node(x)};
  if (length == 0) {
    head = newNode;
    tail = newNode;
    length = 1;
  } else {
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
    length++;
  }
}

void DoublyLinkedList::append(int *arr, int arr_len) {
  for (int i = 0; i < arr_len; i++) {
    append(arr[i]);
  }
}

void DoublyLinkedList::append(const std::vector<int> &vec) {
  for (const auto &n : vec) {
    append(n);
  }
}

void DoublyLinkedList::insert(int index, int x) {
  if (index < 0 || index > length)
    return;
  if (index == 0) {
    prepend(x);
  } else if (index == length) {
    append(x);
  } else {
    Node *temp{head};
    for (int i = 0; i < index; i++) {
      temp = temp->next;
    }
    Node *newNode{new Node(x)};
    newNode->prev = temp->prev;
    temp->prev->next = newNode;
    newNode->next = temp;
    temp->prev = newNode;
    length++;
  }
}

void DoublyLinkedList::insert(int index, int *arr, int arr_len) {
  if (index < 0 || index > length)
    return;
  if (index == 0) {
    prepend(arr, arr_len);
  } else if (index == length) {
    append(arr, arr_len);
  } else {
    for (int i = arr_len - 1; i >= 0; i--) {
      insert(index, arr[i]);
    }
  }
}

void DoublyLinkedList::insert(int index, const std::vector<int> &vec) {
  if (index < 0 || index > length)
    return;
  if (index == 0) {
    prepend(vec);
  } else if (index == length) {
    append(vec);
  } else {
    for (int i = static_cast<int>(vec.size()) - 1; i >= 0; i--) {
      insert(index, vec[i]);
    }
  }
}

void DoublyLinkedList::deleteFirst() {
  if (length == 0)
    return;
  Node *temp{head};
  if (length == 1) {
    head = nullptr;
    tail = nullptr;
  } else {
    head = head->next;
  }
  length--;
  delete temp;
}

void DoublyLinkedList::deleteLast() {
  if (length == 0)
    return;
  Node *temp{tail};
  if (length == 1) {
    head = nullptr;
    tail = nullptr;
  } else {
    tail->prev->next = nullptr;
    tail = tail->prev;
  }
  length--;
  delete temp;
}

void DoublyLinkedList::deleteNode(int index) {
  if (index < 0 || index >= length)
    return;
  if (index == 0) {
    deleteFirst();
  } else if (index == length - 1) {
    deleteLast();
  } else {
    Node *temp{head};
    for (int i = 0; i < index; i++) {
      temp = temp->next;
    }
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    length--;
    delete temp;
  }
}

void DoublyLinkedList::deleteInRange(int start, int end) {
  if (length == 0 || start >= end || start < 0 || end >= length)
    return;
  int index{start};
  for (int i = start; i <= end; i++) {
    deleteNode(start);
  }
}

void DoublyLinkedList::deleteAllNodes() { deleteInRange(0, length - 1); }

void DoublyLinkedList::deleteFirstKNodes(int k) {
  if (length == 0 || k <= 0)
    return;
  for (int i = 0; i < k; i++) {
    deleteFirst();
  }
}

void DoublyLinkedList::deleteDuplicates(int x) {
  if (length == 0)
    return;
  Node *temp{head};
  int index{0};
  while (temp != nullptr) {
    if (temp->val == x)
      break;
    if (temp->next->next == nullptr)
      return;
    index++;
    temp = temp->next;
  }
  if (temp == nullptr)
    return;
  temp = temp->next;
  while (temp != nullptr) {
    if (temp->val == x) {
      if (temp == tail) {
        tail->prev->next = nullptr;
        tail = tail->prev;
        delete temp;
        length--;
        return;
      } else {
        Node *nodeToDelete{temp};
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        temp = temp->next;
        delete nodeToDelete;
      }
      length--;
    } else {
      temp = temp->next;
    }
  }
}

void DoublyLinkedList::set() {
  if (length == 0)
    return;
  Node *temp{head};
  while (temp->next != nullptr) {
    deleteDuplicates(temp->val);
    temp = temp->next;
  }
}

int DoublyLinkedList::pop(int index) {
  if (length == 0 || index < 0 || index >= length)
    return INT_MIN;
  Node *temp{get(index)};
  int num{temp->val};
  deleteNode(index);
  return num;
}

void DoublyLinkedList::sort() {
  std::vector<int> vec;
  Node *temp{head};
  while (temp != nullptr) {
    vec.push_back(temp->val);
    temp = temp->next;
  }
  deleteAllNodes();
  std::sort(vec.begin(), vec.end());
  for (const auto &n : vec) {
    append(n);
  }
}

void DoublyLinkedList::reverse() {
  Node *temp{head};
  head = tail;
  tail = temp;
  Node *after{nullptr};
  Node *before{nullptr};
  for (int i = 0; i < length; i++) {
    after = temp->next;
    temp->next = before;
    before = temp;
    temp = after;
  }
}

void DoublyLinkedList::concatenate(const DoublyLinkedList &dll) {
  Node *temp{dll.head};
  while (temp != nullptr) {
    this->append(temp->val);
    temp = temp->next;
  }
}

// Returns a sorted DLL which contains the union of 2 other DLLs
DoublyLinkedList DoublyLinkedList::Union(const DoublyLinkedList &dll1,
                                         const DoublyLinkedList &dll2) {
  DoublyLinkedList dll{DoublyLinkedList()};
  Node *temp{dll1.head};
  for (int i = 0; i < dll1.length; i++) {
    dll.append(temp->val);
    temp = temp->next;
  }
  temp = dll2.head;
  while (temp != nullptr) {
    bool duplicateFound{false};
    Node *t{dll.head};
    for (int i = 0; i < dll.length; i++) {
      if (temp->val == t->val) {
        duplicateFound = true;
        break;
      }
      t = t->next;
    }
    if (!duplicateFound) {
      dll.append(temp->val);
    }
    temp = temp->next;
  }
  dll.sort();
  return dll;
}

// Returns a sorted DLL which is the intersection of 2 other DLLs
DoublyLinkedList DoublyLinkedList::intersection(const DoublyLinkedList &dll1,
                                                const DoublyLinkedList &dll2) {
  DoublyLinkedList dll{DoublyLinkedList()};
  Node *t1{dll1.head};
  while (t1 != nullptr) {
    Node *t2{dll2.head};
    for (int i = 0; i < dll2.length; i++) {
      if (t1->val == t2->val) {
        dll.append(t1->val);
        break;
      }
      t2 = t2->next;
    }
    t1 = t1->next;
  }
  dll.sort();
  return dll;
}

void DoublyLinkedList::rotate(int k) {
  if (length <= 1) {
    return;
  }
  if (k > length) {
    k = k % length;
  }
  Node *temp{head};
  Node *newHead{head};
  for (int i = 0; i < k; i++) {
    newHead = newHead->next;
  }
  head = newHead;
  for (int i = 0; i < k; i++) {
    temp->prev = tail;
    tail->next = temp;
    tail = temp;
    temp = temp->next;
  }
  tail->next = nullptr;
}
