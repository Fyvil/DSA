#ifndef DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H

#include <iostream>
#include <vector>


class Node {
public:
    int val;
    Node *next;
    Node *prev;
    explicit Node(int x) : val{x}, next{nullptr}, prev{nullptr} {}
    ~Node() {
        next = nullptr;
        prev = nullptr;
    }
};


class DoublyLinkedList {
private:
    Node *head;
    int length;

    // Getters

    [[nodiscard]] Node * getTail() const;
    [[nodiscard]] Node * get(int index) const;
public:
    // Constructors and Destructor

    DoublyLinkedList();
    explicit DoublyLinkedList(int x);
    explicit DoublyLinkedList(const std::vector<int> &vec);
    ~DoublyLinkedList();

    // Utility
    void print() const;
    void details() const;

    // Adding to DLL

    void prepend(int x);
    void prepend(const std::vector<int> &vec);
    void append(int x);
    void append(const std::vector<int> &vec);
    void insert(int index, int x);
    void insert(int index, const std::vector<int> &vec);

    // Removing from DLL

    void deleteFirst();
    void pop();
    void pop(int index);
    void deleteFrom(int start);
    void deleteInRange(int start, int end);

    // Sorting

    void reverse();
    void bubbleSort();
    void reverseSort();

    //concatenation
    DoublyLinkedList & operator+=(const DoublyLinkedList &dll);

    // Removing duplicates(aka set)

    bool set(int x);
    bool set();

    // Merge at alternate positions
    void merge(DoublyLinkedList &dll);

    // Merge at alternate positions up till index of dll
    void merge(DoublyLinkedList &dll, int index);
};


#endif //DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H
