#include <iostream>
#include "doublylinkedlist.h"

int main() {
//    auto *dll = new DoublyLinkedList({1,2,1,2,1,1,1,1,1,1,1,1});
//    auto *d = new DoublyLinkedList({1,2,3,4,5});
    auto dll = DoublyLinkedList({1,2,3});
    auto d = DoublyLinkedList({4,5,6});
//    dll.print();
    dll.bubbleSort();
    dll.append({100, 200, 300 ,400, 500});
    dll.print();
    dll.details();
    return 0;
}
