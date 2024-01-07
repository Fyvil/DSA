#include "doublylinkedlist.h"

#define ARRAY_SIZE 500'000'000

int main() {
  auto *dll{new DoublyLinkedList({1, 2, 3, 4, 5})};
  int arr[]{6, 7, 8, 9};

  // auto *largeDLL{new DoublyLinkedList(largeArray, ARRAY_SIZE)};
  auto *dll2{new DoublyLinkedList({3, 4, 5, 6, 7, 8, 9})};
  dll->concat(*dll2);
  dll->set();
  dll->reverseSublist(0, 4);
  dll->print();
  dll->details();
  delete dll;
  delete dll2;
  return 0;
}
