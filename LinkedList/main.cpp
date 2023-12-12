#include "linkedlist.h"

int main() {
    std::vector<int> myVector{2, 5, 3, 4, 3, 5, 2, 1};
    std::unique_ptr<LinkedList> myLinkedList{std::make_unique<LinkedList>(myVector)};

    myLinkedList->append(10);
    myLinkedList->prepend({7, 9, 1, 6, 2});
    myLinkedList->append({12, 25});

    int arr[]{43, 54, 17, 101};
    int len{4};
    std::unique_ptr<LinkedList> newLinkedList{std::make_unique<LinkedList>(arr, len)};

    *myLinkedList += *newLinkedList;

    myLinkedList->reverse();
    myLinkedList->deleteDuplicates();
    myLinkedList->sort();

    std::unique_ptr<LinkedList> finalLinkedList{LinkedList::add(*myLinkedList, *newLinkedList)};

    myLinkedList->print();
    newLinkedList->print();
    finalLinkedList->print();

    finalLinkedList->details();

    std::unique_ptr<LinkedList> ll{LinkedList::intersection(*myLinkedList, *finalLinkedList)};
    ll->print();
    ll->details();

    return 0;
}
