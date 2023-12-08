#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <cmath>

class Node {
public:
    int val;
    Node *next;

    Node() : val{0}, next{nullptr} {}
    explicit Node(int x) : val{x}, next{nullptr} {}
    ~Node() = default;
};


class LinkedList {
private:
    Node *head;
    Node *tail;
    int length;
public:
    LinkedList();
    explicit LinkedList(int x);
    explicit LinkedList(const std::vector<int> &vec);
    ~LinkedList() {
        while (head != nullptr) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
        length = 0;
    }


    // Getters

    [[nodiscard]] int len() const { return length; }
    [[nodiscard]] Node * getTail() const { return tail; }
    [[nodiscard]] Node * getHead() const { return head; }
    [[nodiscard]] Node * getNodeByIndex(int index) const;
    [[nodiscard]] Node * getNodeByValue(int x) const;
    [[nodiscard]] int getIndex(int x) const;
    [[nodiscard]] static int getNumLength(long long) ;

    // Helpers

    [[nodiscard]] bool foundNode(int x) const;
    [[nodiscard]] bool foundDuplicate(int x) const;
    bool isPalindrome() const;


    // Printing

    void print() const;
    void details() const;


    // Adding nodes

    void prepend(int x);
    void prepend(const std::vector<int> &vec);
    void append(int x);
    void append(const std::vector<int> &vec);
    bool insert(int i, int x);
    bool insert(int i, const std::vector<int> &vec);


    // Deleting nodes

    void deleteFirst();
    void deleteLast();
    bool deleteNode(int i);
    void deleteFirstOccurrence(int x);
    void deleteAllOccurrences(int x);
    void removeDuplicates(int x);
    void removeAllDuplicates();

    // Sorting

    void reverse();
    void reverse(int k);
    void sort();
    void reverseSort();

    // Operator overloading

    LinkedList & operator+=(LinkedList &ll);
    LinkedList & operator*=(LinkedList &ll);

    // Util

    LinkedList & concatenate(LinkedList &ll);
    LinkedList & multiply(LinkedList &ll);
    static LinkedList & addDigitsOfNodes(LinkedList &ll1, LinkedList &ll2);
    void partition(int target);
};


#endif //LINKEDLIST_LINKEDLIST_H
