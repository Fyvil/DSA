#include "doublylinkedlist.h"

DoublyLinkedList::DoublyLinkedList() : head{nullptr}, length{0} {

}

DoublyLinkedList::DoublyLinkedList(int x) {
    Node *t = new Node(x);
    head = t;
    length = 1;
}

DoublyLinkedList::DoublyLinkedList(const std::vector<int> &vec) {
    if (vec.empty()) {
        DoublyLinkedList(0);
    } else {
        Node *n = new Node(vec[0]);
        head = n;
        length = 1;
        Node *p = head;
        for (int i = 1, l = static_cast<int>(vec.size()); i < l; i++) {
            Node *t = new Node(vec[i]);
            p->next = t;
            t->prev = p;
            p = p->next;
            length++;
        }
    }
}

DoublyLinkedList::~DoublyLinkedList() {
    while (head != nullptr) {
        Node *d = head;
        head = head->next;
        delete d;
        length--;
    }
    std::cout << "DLL deallocated" << std::endl;
}

void DoublyLinkedList::print() const {
    if (length < 1) {
        std::cout << "Empty list" << std::endl;
        return;
    }
    Node *t = head;
    while (t != nullptr) {
        std::cout << t->val << " <->  ";
        t = t->next;
    }
    std::cout << "nullptr" << std::endl;
}

void DoublyLinkedList::details() const {
    if (length == 0) return;
    std::cout << "Head: " << head->val << "\nTail: " << getTail()->val << "\nLength: " << length << std::endl;
}

Node *DoublyLinkedList::getTail() const {
    Node *t = head;
    while (t->next != nullptr) {
        t = t->next;
    }
    return t;
}

Node *DoublyLinkedList::get(int index) const {
    if (length == 0 || index < 0 || index >= length) return nullptr;
    if (index == 1) return head;
    Node *t = head;
    for (int i = 0; i < index; i++) {
        t = t->next;
    }
    return t;
}

void DoublyLinkedList::prepend(int x) {
    if (length == 0) return;
    Node *n = new Node(x);
    Node *t = head;
    head = n;
    head->next = t;
    t->prev = head;
    length++;
}

void DoublyLinkedList::prepend(const std::vector<int> &vec) {
    if (length == 0) return;
    int n = static_cast<int>(vec.size()) - 1;
    for (int i = n; i >= 0; i--) {
        prepend(vec[i]);
    }
}

void DoublyLinkedList::append(int x) {
    if (length == 0) return;
    Node *t = getTail();
    Node *n = new Node(x);
    t->next = n;
    n->prev = t;
    length++;
}

void DoublyLinkedList::append(const std::vector<int> &vec) {
    if (length == 0) return;
    for (const auto &n: vec) {
        append(n);
    }
}

void DoublyLinkedList::insert(int index, int x) {
    if (length == 0 || index < 0 || index > length) return;
    if (index == 0) {
        prepend(x);
    } else if (index == length) {
        append(x);
    } else {
        Node *t = head;
        for (int i = 0; i < index - 1; i++) {
            t = t->next;
        }
        Node *n = new Node(x);
        n->next = t->next;
        t->next->prev = n;
        t->next = n;
        n->prev = t;
        length++;
    }
}

void DoublyLinkedList::insert(int index, const std::vector<int> &vec) {
    if (length == 0 || index < 0 || index > length) return;
    if (index == 0) {
        prepend(vec);
    } else if (index == length) {
        append(vec);
    } else {
        Node *t = head;
        for (int i = 0; i < index - 1; i++) {
            t = t->next;
        }
        for (const auto &num: vec) {
            Node *n = new Node(num);
            n->next = t->next;
            t->next->prev = n;
            t->next = n;
            n->prev = t;
            length++;
            t = t->next;
        }
    }
}

void DoublyLinkedList::deleteFirst() {
    if (length <= 1) return;
    Node *t = head;
    head = head->next;
    delete t;
    length--;
}

void DoublyLinkedList::pop() {
    Node *t = head;
    while (t->next != nullptr) {
        t = t->next;
    }
    t->prev->next = nullptr;
    delete t;
    length--;
}

void DoublyLinkedList::pop(int index) {
    if (length <= 1 || index >= length) return;
    if (index == 0) {
        deleteFirst();
    } else if (index == length - 1) {
        pop();
    } else {
        Node *t = head;
        for (int i = 0; i < index; i++) {
            t = t->next;
        }
        t->next->prev = t->prev;
        t->prev->next = t->next;
        delete t;
        length--;
    }
}

void DoublyLinkedList::deleteFrom(int start) {
    if (length == 0 || start <= 0 || start >= length) return;
    if (start == length - 1) {
        pop();
        return;
    }
    Node *t = head;
    for (int i = 0; i < start; i++) {
        t = t->next;
    }
    while (t != nullptr) {
        Node *d = t;
        if (t->next == nullptr) {
            pop();
            return;
        }
        t->next->prev = t->prev;
        t->prev->next = t->next;
        t = t->next;
        delete d;
        length--;
    }
}

// Deletes nodes from index start up till index end (start inclusive and end non-inclusive) -> from start up to end
void DoublyLinkedList::deleteInRange(int start, int end) {
    if (length <= 1 || start < 0 || end >= length) return;
    if (end - start > length) return;
    if (start == 0) {
        for (int i = 0; i < end; i++) {
            deleteFirst();
        }
    } else if (end - start == 1) {
        pop(start);
    } else {
        Node *t = head;
        for (int i = 0; i < start; i++) {
            t = t->next;
        }
        int counter{0};
        while (counter != end - 1) {
            Node *d = t;
            t->next->prev = t->prev;
            t->prev->next = t->next;
            t = t->next;
            delete d;
            length--;
            counter++;
        }
    }
}

void DoublyLinkedList::reverse() {
    if (length <= 1) return;
    Node *t = head;
    head = getTail();
    Node *after{nullptr};
    Node *before{nullptr};
    for (int i = 0; i < length; i++) {
        after = t->next;
        t->next = before;
        before = t;
        t = after;
    }
}

void DoublyLinkedList::bubbleSort() {
    int swapCounter{-1};
    while (swapCounter != 0) {
        swapCounter = 0;
        Node *t = head;
        for (int i = 0; i < length - 1; i++) {
            if (t->val > t->next->val) {
                int temp{t->next->val};
                t->next->val = t->val;
                t->val = temp;
                swapCounter++;
            }
            t = t->next;
        }
    }
}

void DoublyLinkedList::reverseSort() {
    bubbleSort();
    reverse();
}

DoublyLinkedList &DoublyLinkedList::operator+=(const DoublyLinkedList &dll) {
    Node *tail = this->getTail();
    Node *t = dll.head;
    while (t != nullptr) {
        t->prev = tail;
        tail->next = t;
        tail = t;
        t = t->next;
        length++;
    }
    return *this;
}

// Removes all nodes containing duplicates of a specified value if it exists
bool DoublyLinkedList::set(int x) {
    if (length <= 1) return false;
    Node *t{head};
    for (int i = 0; i < length; i++) {
        if (t->val == x) break;
        if (t->next == nullptr) return false;
        t = t->next;
    }
    while (t->next != nullptr) {
        if (t->next->val == x) {
            if (t->next->next == nullptr) {
                pop();
                return true;
            }
            Node *d = t->next;
            t->next->next->prev = t;
            t->next = t->next->next;
            delete d;
            length--;
        } else {
            t = t->next;
        }
    }
    return true;
}

// Removes all duplicates of all values present in the DLL
bool DoublyLinkedList::set() {
    if (length <= 1) return false;
    Node *slow{head};
    bool end = false;
    while (slow->next != nullptr) {
        Node *fast{slow->next};
        while (fast != nullptr) {
            if (slow->val == fast->val) {
                if (fast->next == nullptr) {
                    if (slow->next->next == nullptr) {
                        end = true;
                    }
                    Node *dd = fast;
                    fast->prev->next = nullptr;
                    delete dd;
                    length--;
                    break;
                }
                Node *d = fast;
                fast->next->prev = fast->prev;
                fast->prev->next = fast->next;
                fast = fast->next;
                delete d;
                length--;
            } else {
                fast = fast->next;
            }
        }
        if (!end) {
            slow = slow->next;
        }
    }
    return true;
}

void DoublyLinkedList::merge(DoublyLinkedList &dll) {
    if (length <= 0 || dll.length <= 0) return;
    Node *t1 {head};
    for (int i = 0; i < length; i++) {
        if (t1->next == nullptr || dll.head->next == nullptr) break;
        Node *t2 {dll.head};
        dll.head = dll.head->next;
        t2->prev = t1;
        t2->next = t1->next;
        t1->next->prev = t2;
        t1->next = t2;
        t1 = t2->next;
        length++;
        dll.length--;
    }
    if (length >= dll.length) {
        if (t1->next == nullptr) {
            dll.head->prev = t1;
            t1->next = dll.head;
        } else {
            t1->next->prev = dll.head;
            dll.head->prev = t1;
            dll.head->next = t1->next;
            t1->next = dll.head;
        }
        length++;
        dll.length--;
        dll.head = nullptr;
    }
}

void DoublyLinkedList::merge(DoublyLinkedList &dll, int index) {
    
}

