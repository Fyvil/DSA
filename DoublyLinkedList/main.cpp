#include "doublylinkedlist.h"

#define ARRAY_SIZE 50'000'000

int main() {
  auto *dll{new DoublyLinkedList({1, 2, 3, 4, 5})};
  int arr[]{6, 7, 8, 9};
  int *largeArray{new int[ARRAY_SIZE]};
  for (int i = 0; i < ARRAY_SIZE; i++) {
    largeArray[i] = (ARRAY_SIZE - i) * 2;
  }
  // auto *largeDLL{new DoublyLinkedList(largeArray, ARRAY_SIZE)};
  DoublyLinkedList largeDLL{DoublyLinkedList(largeArray, ARRAY_SIZE)};
  delete[] largeArray;
  largeDLL.sort();
  largeDLL.print();
  largeDLL.details();
  delete dll;
  return 0;
}
