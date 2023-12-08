#include "linkedlist.h"

LinkedList::LinkedList() {
    Node *newNode = new Node(0);
    head = newNode;
    tail = newNode;
    length = 1;
}

LinkedList::LinkedList(int x) {
    Node *newNode = new Node(x);
    head = newNode;
    tail = newNode;
    length = 1;
}

LinkedList::LinkedList(const std::vector<int> &vec) {
    if (vec.empty()) {
        LinkedList();
    } else {
        Node *firstNode = new Node(vec[0]);
        head = firstNode;
        tail = firstNode;
        length = 1;
        Node *temp = head;
        for (int i = 1, n = static_cast<int>(vec.size()); i < n; i++) {
            Node *newNode = new Node(vec[i]);
            temp->next = newNode;
            tail = newNode;
            length++;
            temp = temp->next;
        }
    }
}

Node *LinkedList::getNodeByIndex(int index) const {
    if (index >= length) return nullptr;
    if (index == 0) return head;
    if (index == length-1) return tail;
    Node *temp = head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return temp;
}

// Returns the first node found with a specified value
Node *LinkedList::getNodeByValue(int x) const {
    Node *temp = head;
    while (temp != nullptr) {
        if (temp->next == nullptr) return tail;
        if (temp->val == x) break;
        temp = temp->next;
    }
    return temp;
}

// Gets index of the first occurrence of a particular node object with specified value
int LinkedList::getIndex(int x) const {
    Node *temp = head;
    int index {0};
    while (temp != nullptr) {
        if (temp->val == x) return index;
        temp = temp->next;
        index++;
    }
    return -1;
}

// Checks if node containing specified value exists
bool LinkedList::foundNode(int x) const {
    if (length == 0) return false;
    Node *temp = head;
    while (temp != nullptr) {
        if (temp->val == x) return true;
        temp = temp->next;
    }
    return false;
}

// Checks if a duplicate of specified value exists
bool LinkedList::foundDuplicate(int x) const {
    if (!foundNode(x) || length <= 1) return false;
    Node *slow = head;
    while (slow->next != nullptr) {
        if (slow->next == nullptr) return false;
        if (slow->val == x) break;
        slow = slow->next;
    }
    Node *fast = slow->next;
    while (fast != nullptr) {
        if (fast->val == slow->val) return true;
        fast = fast->next;
    }
    return false;
}

void LinkedList::print() const {
    if (length == 0) {
        std::cout << "Empty linked list. Consider adding nodes." << std::endl;
        return;
    }
    Node *temp = head;
    while (temp != nullptr) {
        std::cout << temp->val << " -> ";
        temp = temp->next;
    }
    std::cout << "nullptr" << std::endl;
}

void LinkedList::details() const {
    if (length == 0 || getHead() == nullptr || getTail() == nullptr) {
        std::cout << "Empty Linked List" << std::endl;
        return;
    }
    std::cout << "Length: " << length << '\n';
    std::cout << "Head: " << getHead()->val << '\n';
    std::cout << "Tail: " << getTail()->val << std::endl;
}

void LinkedList::prepend(int x) {
    Node *newNode = new Node(x);
    Node *temp = head;
    head = newNode;
    head->next = temp;
    length++;
}

void LinkedList::prepend(const std::vector<int> &vec) {
    for (int i = static_cast<int>(vec.size()) - 1; i >= 0; i--) {
        prepend(vec[i]);
    }
}

void LinkedList::append(int x) {
    Node *newNode = new Node(x);
    if (length == 0) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    length++;
}

void LinkedList::append(const std::vector<int> &vec) {
    for (const auto &n: vec) {
        append(n);
    }
}

// Inserts node at specified index
bool LinkedList::insert(int i, int x) {
    if (i < 0 || i >= length) return false;
    if (i == 0) {
        prepend(x);
    } else {
        Node *prev = head;
        for (int j = 0; j < i - 1; j++) {
            prev = prev->next;
        }
        Node *newNode = new Node(x);
        newNode->next = prev->next;
        prev->next = newNode;
        length++;
    }
    return true;
}

// Inserts nodes from a vector at a specified index
bool LinkedList::insert(int i, const std::vector<int> &vec) {
    if (i < 0 || i > length) return false;
    if (i == 0) {
        prepend(vec);
    } else if (i == length) {
        append(vec);
    } else {
        int index{0};
        for (int j = i, n = static_cast<int>(vec.size()); j <= n; j++) {
            insert(j, vec[index]);
            index++;
        }
    }
    return true;
}

void LinkedList::pop() {
    if (length == 0) return;
    Node *temp = head;
    if (length == 1) {
        head = nullptr;
        tail = nullptr;
    } else {
        head = head->next;
    }
    delete temp;
    length--;
}

void LinkedList::deleteLast() {
    if (length == 0) return;
    if (length == 1) {
        pop();
    } else {
        Node *temp = head;
        while (temp->next != nullptr) {
            if (temp->next->next == nullptr) break;
            temp = temp->next;
        }
        tail = temp;
        tail->next = nullptr;
        delete temp->next;
        length--;
    }
}

bool LinkedList::deleteNode(int i) {
    if (i < 0 || i >= length) return false;
    if (i == 0) {
        pop();
    } else if (i == length - 1) {
        deleteLast();
    } else {
        Node *temp = head;
        for (int j = 0; j < i - 1; j++) {
            temp = temp->next;
        }
        Node *d = temp->next;
        temp->next = d->next;
        delete d;
        length--;
    }
    return true;
}

void LinkedList::deleteFirstOccurrence(int x) {
    if (length == 0) return;
    Node *temp = head;
    int index {0};
    while (temp != nullptr) {
        if (temp->val == x) {
            deleteNode(index);
            return;
        } else {
            temp = temp->next;
            index++;
        }
    }
}

void LinkedList::deleteAllOccurrences(int x) {
    while (foundNode(x)) {
        deleteFirstOccurrence(x);
    }
}

void LinkedList::removeDuplicates(int x) {
    if (!foundDuplicate(x) || length <= 1) return;
    Node *temp = getNodeByValue(x);
    while (temp->next != nullptr) {
        if (temp->next->val == x) {
            if (length == 2 || temp->next->next == nullptr) {
                deleteLast();
            } else {
                Node *nodeToDelete = temp->next;
                temp->next = nodeToDelete->next;
                delete nodeToDelete;
                length--;
            }
        } else {
            temp = temp->next;
        }
    }
}

void LinkedList::removeAllDuplicates() {
    if (length <= 1) return;
    Node *temp = head;
    while (temp->next != nullptr) {
        if (foundDuplicate(temp->val)) {
            removeDuplicates(temp->val);
        }
        temp = temp->next;
    }
}

void LinkedList::reverse() {
    if (length <= 1) return;
    Node *before {nullptr};
    Node *after {nullptr};
    Node *temp = head;
    head = tail;
    tail = temp;
    for (int i = 0; i < length; i++) {
        after = temp->next;
        temp->next = before;
        before = temp;
        temp = after;
    }
}

// Reverse first k nodes
void LinkedList::reverse(int k) {
    if (length <= 1 || k > length) return;
    if (k == length) {
        reverse();
        return;
    }
    Node *after {nullptr};
    Node *before {nullptr};
    Node *temp {head};
    tail = head;
    head = getNodeByIndex(k-1);
    for (int i = 0; i < k; i++) {
        after = temp->next;
        temp->next = before;
        before = temp;
        temp = after;
    }
    while (temp != nullptr) {
        tail->next = temp;
        tail = temp;
        temp = temp->next;
    }
}

// Bubble sort (should move to merge/quick)
void LinkedList::sort() {
    int swapCounter {-1};
    while (swapCounter != 0) {
        Node *temp = head;
        swapCounter = 0;
        for (int i = 0; i < length - 1; i++) {
            if (temp->val > temp->next->val) {
                int t = temp->next->val;
                temp->next->val = temp->val;
                temp->val = t;
                swapCounter++;
            }
            temp = temp->next;
        }
    }
}

void LinkedList::reverseSort() {
    sort();
    reverse();
}

// Concatenates another linked list to the end
LinkedList &LinkedList::concatenate(LinkedList &ll) {
    while (ll.head != nullptr) {
        this->tail->next = ll.head;
        this->tail = ll.head;
        ll.head = ll.head->next;
        length++;
    }
    ll.head = nullptr;
    ll.tail = nullptr;
    tail->next = nullptr;
    return *this;
}

LinkedList &LinkedList::operator+=(LinkedList &ll) {
    return concatenate(ll);
}

LinkedList &LinkedList::multiply(LinkedList &ll) {
    Node *t1 {this->head};
    Node *t2 {ll.head};
    for (int i = 0; i < this->length; i++) {
        if (t2 != nullptr) {
            t1->val *= t2->val;
            t2 = t2->next;
        }
        t1 = t1->next;
    }
    if (this->length < ll.length) {
        while (t2 != nullptr) {
            this->append(t2->val);
            t2 = t2->next;
        }
    }
    return *this;
}

LinkedList &LinkedList::operator*=(LinkedList &ll) {
    return multiply(ll);
}

bool LinkedList::isPalindrome() const {
    std::string straight {};
    Node *temp = head;
    while (temp != nullptr) {
        straight += static_cast<char>(temp->val + 48);
        temp = temp->next;
    }
    std::string reversed = straight;
    std::reverse(reversed.begin(), reversed.end());
    if (reversed == straight) return true;
    return false;
}

 LinkedList &LinkedList::addDigitsOfNodes(LinkedList &ll1, LinkedList &ll2) {
    long long result {0};
    Node *temp = ll1.head;
    long long num {0};
    int index {0};
    while (temp != nullptr) {
        num += temp->val * static_cast<long long>(std::pow(10, ll1.length - 1 - index));
        index++;
        temp = temp->next;
    }
    result += num;
    temp = ll2.head;
    index = 0;
    while (temp != nullptr) {
        result += temp->val * static_cast<long long>(std::pow(10, ll2.length - 1 - index));
        index++;
        temp = temp->next;
    }
    auto *ll = new LinkedList(static_cast<int>(result % static_cast<long long>(10)));
    result /= 10;
    while (result > 0) {
        ll->prepend((static_cast<int>(result % static_cast<long long>(10))));
        result /= static_cast<long long>(10);
    }
    return *ll;
}

int LinkedList::getNumLength(long long x) {
    int c {0};
    while (x > 0) {
        x /= 10;
        c++;
    }
    return c;
}

void LinkedList::partition(int target) {
    
}


