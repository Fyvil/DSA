#include "./linkedlist.h"

int main() {
  int arr[]{100, 200, 300, 400, 500};
  auto *ll{new LinkedList({1, 2, 3, 4, 5})};
  ll->makeEmpty();
  ll->print();
  ll->details();
  delete ll;
  return 0;
}
