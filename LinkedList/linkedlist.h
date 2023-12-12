/* A Linked List consists of 'nodes'. Each node has a value and a pointer to the 'next' node. The final node in the
list points to nullptr. This implementation will use integers as the value held by the nodes. */

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

class Node {
public:
    int val;
    std::shared_ptr<Node> next;
    explicit Node(int x) : val{x}, next{nullptr} {}
    ~Node() = default;
};


class LinkedList {
private:
    std::shared_ptr<Node> head;
    std::shared_ptr<Node> tail;
    int length;
    // Getters
    [[nodiscard]] std::shared_ptr<Node> getHead() const { return head; }
    [[nodiscard]] std::shared_ptr<Node> getTail() const { return tail; }
    [[nodiscard]] int getLength() const { return length; }
    // Returns node at specified index
    std::shared_ptr<Node> get(int index);
    // Returns first node with a specified value if it exists
    std::shared_ptr<Node> getByValue(int x);
    // Returns index of first node with specified value if it exists
    [[nodiscard]] int getIndex(int x);

public:
    LinkedList() : head{nullptr}, tail{nullptr}, length{0} {}
    explicit LinkedList(int x);
    LinkedList(int *arr, int arr_len);
    explicit LinkedList(const std::vector<int> &vec);
    ~LinkedList();


    void print() const;
    void details() const;

    // Public getters
    [[nodiscard]] int size() const { return length; }
    [[nodiscard]] int headValue() const { return head->val; }
    [[nodiscard]] int tailValue() const { return tail->val; }


    // Adding nodes to the linked list

    // Adds node to the head of the linked list
    void prepend(int x);

    // Adds a vector in order to the head of the linked list
    void prepend(const std::vector<int> &vec);

    // Adds node to the end (tail) of the linked list
    void append(int x);

    // Adds a vector in order to the tail of the linked list
    void append(const std::vector<int> &vec);

    // Inserts a node of specified value at specified index
    bool insert(int index, int x);


    // Deleting nodes from the linked list

    // Deletes first (head) node in the linked list
    void deleteFirst();
    // Deletes last (tail) node in the linked list
    void deleteLast();
    // Deletes first k nodes in the linked list
    void deleteKNodes(int k);
    // Deletes node at specified index
    void deleteNode(int index);
    // Deletes first node with specified value if it exists
    void deleteNodeByValue(int x);
    // Deletes all nodes in range from start (inclusive) to end (non-inclusive)
    void deleteInRange(int start, int end);
    // Empties the linked list
    void deleteAll();
    // Checks if linked list is empty
    [[nodiscard]] bool empty() const;
    // Deletes all duplicates of specified value if they exist
    void deleteDuplicates(int x);
    // Deletes all duplicates of all values if duplicates exist
    void deleteDuplicates();


    // uses std::sort() - should implement a merge sort
    void sort();
    // Uses bubble sort
    void bubbleSort();

    // reverses the linked list in place
    void reverse();

    // concatenate with operator overloading the += operator
    LinkedList& concatenate(const LinkedList& ll);
    LinkedList& operator+=(const LinkedList& ll);

    // Returns a unique pointer to a new list after adding the nodes of 2 linked list
    static std::unique_ptr<LinkedList> add(const LinkedList &ll1, const LinkedList &ll2);

    // Checks if a linked list is a palindrome
    bool isPalindrome();

    // Creates and returns a new LL representing intersection (common elements) of two provided linked lists
    static std::unique_ptr<LinkedList> intersection(LinkedList ll1, LinkedList ll2);
};


#endif //LINKEDLIST_LINKEDLIST_H
