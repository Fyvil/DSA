#include "./linkedlist.h"

int main() {
  int arr[]{100, 200, 300, 400, 500};
  auto *ll{new LinkedList({5, 5, 5, 5, 5, 5, 5, 4, 3, 2, 1, 2, 1, 1,
                           1, 1, 2, 2, 2, 3, 3, 4, 5, 1, 1, 1, 1})};
  ll->set();
  ll->bubbleSort();
  ll->reverse();
  ll->print();
  ll->details();
  delete ll;
  return 0;
}
