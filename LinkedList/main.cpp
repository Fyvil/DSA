#include <iostream>
#include "linkedlist.h"

int main() {
    auto ll = LinkedList({1, 2, 3, 4});
    auto newll = LinkedList({5, 6, 7, 8});
    auto sum = LinkedList::addDigitsOfNodes(ll, newll);
    sum.reverse();
    sum.sort();
    sum.deleteFirst();
    sum.print();
    sum.details();
    
    return 0;
}
