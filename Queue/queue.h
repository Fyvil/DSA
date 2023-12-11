#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

#include <iostream>
#include <memory>
#include <vector>

class Node {
public:
    int val;
    std::shared_ptr<Node> next;
    explicit Node(int x) : val{x}, next{nullptr} {}
    ~Node() = default;
};


class Queue {
private:
    std::shared_ptr<Node> first;
    std::shared_ptr<Node> last;
    int length;
public:
    explicit Queue(int x);
    explicit Queue(const std::vector<int> &vec);
    ~Queue();

    void print() const;
    void details() const;

    bool enqueue(int x);
    bool enqueue(const std::vector<int> &vec);
    bool dequeue();
    bool dequeue(int k);
};


#endif //QUEUE_QUEUE_H
