#include "doublylinkedlist.h"
#include <memory>

int main() {
  int arr[]{3, 1, 1, 8, 8, 8, 81, 1, 1, 12, 3, 4};
  int arr_len{11};
  std::vector<int> vec{5, 6, 7, 8, 1, 1, 3, 4, 4, 3, 1, 2, 4, 1, 1, 8};

  std::unique_ptr<DoublyLinkedList> dll{
      std::make_unique<DoublyLinkedList>(arr, arr_len)};

  std::vector<int> newVec{-1, 1, 2, 3, -2, 10, 100};

  std::unique_ptr<DoublyLinkedList> newdll{
      std::make_unique<DoublyLinkedList>(newVec)};

  dll->insert(arr_len, vec);
  dll->set();
  dll->sort();
  dll->deleteLast();
  dll->deleteLast();

  dll->print();
  dll->details();
  newdll->print();
  newdll->details();

  DoublyLinkedList unionDLL{DoublyLinkedList::Union(*dll, *newdll)};
  unionDLL.print();
  unionDLL.details();

  DoublyLinkedList intersectionDLL{
      DoublyLinkedList::intersection(unionDLL, *newdll)};
  intersectionDLL.print();
  intersectionDLL.details();

  unionDLL.rotate(5);
  unionDLL.print();
  unionDLL.details();
  return 0;
}
