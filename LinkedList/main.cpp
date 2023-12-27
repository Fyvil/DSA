#include "./linkedlist.h"

int main() {
  int arr[]{100, 200, 300, 400, 500};
  LinkedList ll;
  for (int i = 1; i <= 2'000'000; i++) {
    ll.prepend(i);
  }
  ll.sort();
  ll.print();
  ll.details();
  auto *ll2{new LinkedList({55, -1, 2, 0, 32, -11, 12})};
  ll2->sort();
  ll2->reverse();
  ll2->print();
  ll2->details();
  return 0;
}
