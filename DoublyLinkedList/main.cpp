#include "doublylinkedlist.h"

int main() {
  auto *dll{new DoublyLinkedList({1, 2, 3, 4, 5})};
  int arr[]{6, 7, 8, 9};
  dll->append(arr, 4);
  dll->reverse();
  dll->sort();
  dll->print();
  dll->details();
  delete dll;
  return 0;
}
