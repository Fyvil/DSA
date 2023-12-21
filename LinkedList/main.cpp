#include "./linkedlist.h"

int main() {
  auto *ll{new LinkedList({1, 2, 3, 4, 5})};
  ll->print();
  ll->details();
  return 0;
}
