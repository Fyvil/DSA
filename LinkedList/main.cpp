#include "./linkedlist.h"

int main() {
  int arr[]{100, 200, 300, 400, 500};
  auto *ll{new LinkedList({5, 5, 5, 5, 5, 5, 5, 4, 3, 2, 1, 2, 1, 1,
                           1, 1, 2, 2, 2, 3, 3, 4, 5, 1, 1, 1, 1})};
  ll->set();
  ll->bubbleSort();
  auto *ll2{new LinkedList({-1, 0, 1, 3, 5})};
  ll->append({6, 7, 8});
  LinkedList ll3{LinkedList::merge(*ll, *ll2)};
  ll3.print();
  ll3.details();
  // delete ll;
  // delete ll2;
  return 0;
}
