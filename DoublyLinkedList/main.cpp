#include "doublylinkedlist.h"
#include <memory>

int main() {
  int arr[]{3, 1, 1, 8, 8, 8, 81, 1, 1, 12, 3, 4};
  int arr_len{11};
  std::vector<int> vec{5, 6, 7, 8, 1, 1, 3, 4, 4, 3, 1, 2, 4, 1, 1, 8};
  std::unique_ptr<DoublyLinkedList> dll{
      std::make_unique<DoublyLinkedList>(arr, arr_len)};
  std::vector<int> newVec{61, 5, 6, 7, 8, 1};
  std::unique_ptr<DoublyLinkedList> newdll{
      std::make_unique<DoublyLinkedList>(newVec)};
  dll->insert(arr_len, vec);
  dll->set();
  dll->sort();
  dll->merge(*newdll);
  dll->set();
  dll->sort();

  dll->print();
  dll->details();
  return 0;
}
