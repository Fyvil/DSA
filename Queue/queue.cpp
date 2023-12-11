#include "queue.h"

Queue::Queue(int x) {
    std::shared_ptr<Node> n {std::make_shared<Node>(x)};
    first = n;
    last = n;
    length = 1;
}

Queue::Queue(const std::vector<int> &vec) {
    if (vec.empty()) return;
    std::shared_ptr<Node> firstNode {std::make_shared<Node>(vec[0])};
    length = 1;
    first = firstNode;
    last = firstNode;
    if (vec.size() == 1) return;
    for (int i = 1, n = static_cast<int>(vec.size()); i < n; i++) {
        std::shared_ptr<Node> t {std::make_shared<Node>(vec[i])};
        last->next = t;
        last = t;
        length++;
    }
}

Queue::~Queue() {
    while (first != nullptr) {
        std::shared_ptr<Node> d {first};
        first = first->next;
        length--;
    }
}

void Queue::print() const {
    if (length == 0) {
        std::cout << "Queue is empty" << std:endl;
        return;
    }
    std::shared_ptr<Node> t {first};
    while (t != nullptr) {
        std::cout << t->val << " -> ";
        t = t->next;
    }
    std::cout << "nullptr" << std::endl;
}

void Queue::details() const {
    if (length == 0) {
        std::cout << "First: NONE\nLast: NONE\nLength: 0" << std::endl;
        return;
    }
    std::cout << "First: " << first->val << "\nLast: " << last->val << "\nLength: " << length << std::endl;
}

bool Queue::enqueue(int x) {
    if (length == 0) return false;
    std::shared_ptr<Node> n {std::make_shared<Node>(x)};
    last->next = n;
    last = n;
    length++;
    return true;
}

bool Queue::enqueue(const std::vector<int> &vec) {
    if (vec.empty() || length == 0) return false;
    for (const auto &num: vec) {
        enqueue(num);
    }
    return true;
}

bool Queue::dequeue() {
    if (length <= 1) return false;
    std::shared_ptr<Node> d {first};
    first = first->next;
    length--;
    return true;
}

// Dequeues first k nodes
bool Queue::dequeue(int k) {
    if (length <= 1 || k > length) return false;
    for (int i = 0; i < k; i++) {
        dequeue();
    }
    return true;
}



