#include "linkedlist.h"

LinkedList::LinkedList(int x) {
    std::shared_ptr<Node> newNode{std::make_shared<Node>(x)};
    head = newNode;
    tail = newNode;
    length = 1;
}

LinkedList::LinkedList(int *arr, int arr_len) {
    std::shared_ptr<Node> newNode{std::make_shared<Node>(arr[0])};
    head = newNode;
    tail = newNode;
    length = 1;
    for (int i = 1; i < arr_len; i++) {
        newNode = std::make_shared<Node>(arr[i]);
        tail->next = newNode;
        tail = newNode;
        length++;
    }
}


LinkedList::LinkedList(const std::vector<int> &vec) {
    if (vec.empty()) return;
    std::shared_ptr<Node> newNode{std::make_shared<Node>(vec[0])};
    head = newNode;
    tail = head;
    length = 1;
    for (int i = 1, n = static_cast<int>(vec.size()); i < n; i++) {
        newNode = std::make_shared<Node>(vec[i]);
        tail->next = newNode;
        tail = newNode;
        length++;
    }
}

LinkedList::~LinkedList() {
    while (head != nullptr) {
        std::shared_ptr<Node> temp{head};
        head = head->next;
        length--;
    }
    head = nullptr;
    tail = nullptr;
}

void LinkedList::print() const {
    if (length == 0) {
        std::cout << "Linked List is empty. Consider adding elements." << std::endl;
        return;
    }
    std::shared_ptr<Node> temp{head};
    for (int i = 0; i < length; i++) {
        std::cout << temp->val << " -> ";
        temp = temp->next;
    }
    std::cout << "nullptr" << std::endl;
}

void LinkedList::details() const {
    if (length == 0) {
        std::cout << "Empty Linked List." << std::endl;
    } else {
        std::cout << "Head: " << head->val << "\nTail: " << tail->val << "\nLength: " << length << std::endl;
    }
}

std::shared_ptr<Node> LinkedList::get(int index) {
    if (index < 0 || index > length) return nullptr;
    if (index == 0) {
        return getHead();
    } else if (index == length - 1) {
        return getTail();
    } else {
        std::shared_ptr<Node> temp{head};
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp;
    }
}

std::shared_ptr<Node> LinkedList::getByValue(int x) {
    if (length == 0) return nullptr;
    if (head->val == x) return getHead();
    std::shared_ptr<Node> temp{head};
    while (temp->next != nullptr) {
        if (temp->next == nullptr) return nullptr;
        if (temp->next->val == x) break;
        temp = temp->next;
    }
    return temp->next;
}

int LinkedList::getIndex(int x) {
    std::shared_ptr<Node> temp{head};
    for (int i = 0; i < length; i++) {
        if (temp->val == x) return i;
        temp = temp->next;
    }
    return -1;
}

void LinkedList::prepend(int x) {
    std::shared_ptr<Node> newNode {std::make_shared<Node>(x)};
    if (length == 0) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    length++;
}

void LinkedList::prepend(const std::vector<int> &vec) {
    if (vec.empty()) return;
    for (int i = static_cast<int>(vec.size() - 1); i >= 0; i--) {
        prepend(vec[i]);
    }
}

void LinkedList::append(int x) {
    std::shared_ptr<Node> newNode {std::make_shared<Node>(x)};
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
    if (vec.empty()) return;
    for (const auto &num: vec) {
        append(num);
    }
}

bool LinkedList::insert(int index, int x) {
    if (index < 0 || index > length) return false;
    if (index == 0) {
        prepend(x);
    } else if (index == length) {
        append(x);
    } else {
        std::shared_ptr<Node> temp{head};
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        std::shared_ptr<Node> newNode{std::make_shared<Node>(x)};
        newNode->next = temp->next;
        temp->next = newNode;
        length++;
    }
    return true;
}

void LinkedList::deleteFirst() {
    if (length == 0) return;
    std::shared_ptr<Node> nodeToDelete{head};
    if (length == 1) {
        head = nullptr;
        tail = nullptr;
    } else {
        head = head->next;
    }
    length--;
}

void LinkedList::deleteLast() {
    if (length == 0) return;
    std::shared_ptr<Node> nodeToDelete{head};
    if (length == 1) {
        head = nullptr;
        tail = nullptr;
    } else {
        while (nodeToDelete->next != tail) {
            nodeToDelete = nodeToDelete->next;
        }
        tail = nodeToDelete;
        tail->next = nullptr;
    }
    length--;
}

void LinkedList::deleteKNodes(int k) {
    if (k > length || k <= 0) return;
    for (int i = 0; i < k; i++) {
        deleteFirst();
    }
}

void LinkedList::deleteNode(int index) {
    if (index < 0 || index >= length || length == 0) return;
    if (index == 0) {
        deleteFirst();
    } else if (index == length - 1) {
        deleteLast();
    } else {
        std::shared_ptr<Node> temp{head};
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        length--;
    }
}

void LinkedList::deleteNodeByValue(int x) {
    if (length == 0) return;
    if (head->val == x) {
        deleteFirst();
        return;
    }
    std::shared_ptr<Node> nodeToDelete{head};
    while (nodeToDelete->next != nullptr) {
        if (nodeToDelete->next == nullptr) return;
        if (nodeToDelete->next->val == x) break;
        nodeToDelete = nodeToDelete->next;
    }
    if (nodeToDelete->next->next == nullptr) {
        tail = nodeToDelete->next;
        tail->next = nullptr;
    } else {
        nodeToDelete->next = nodeToDelete->next->next;
    }
    length--;
}

void LinkedList::deleteInRange(int start, int end) {
    if (length == 0 || end <= start || end > length) return;
    for (int i = start; i < end; i++) {
        deleteNode(start);
    }
}

void LinkedList::deleteAll() {
    while (length != 0) {
        deleteFirst();
    }
}

bool LinkedList::empty() const {
    if (length == 0) return true;
    return false;
}

void LinkedList::deleteDuplicates(int x) {
    std::shared_ptr<Node> temp{getByValue(x)};
    int index{getIndex(x)};
    if (temp == nullptr || index == -1) return;
    while (temp->next != nullptr) {
        if (temp->next->val == x) {
            deleteNode(index + 1);
        } else {
            temp = temp->next;
            index++;
        }
    }
}

void LinkedList::deleteDuplicates() {
    std::shared_ptr<Node> temp{head};
    while (temp != nullptr) {
        deleteDuplicates(temp->val);
        temp = temp->next;
    }
}

void LinkedList::sort() {
    std::vector<int> vec;
    while (head != nullptr) {
        vec.push_back(head->val);
        deleteFirst();
    }
    std::sort(vec.begin(), vec.end());
    for (int i = 0, n = static_cast<int>(vec.size() - 1); i < n; i++) {
        append(vec[i]);
    }
}

void LinkedList::bubbleSort() {
    int swapCounter {-1};
    while (swapCounter != 0) {
        swapCounter = 0;
        std::shared_ptr<Node> temp {head};
        for (int i = 0; i < length - 1; i++) {
            if (temp->val > temp->next->val) {
                std::swap(temp->val, temp->next->val);
                swapCounter++;
            }
            temp = temp->next;
        }
    }
}

void LinkedList::reverse() {
    std::shared_ptr<Node> temp{head};
    head = tail;
    tail = temp;
    std::shared_ptr<Node> after{nullptr};
    std::shared_ptr<Node> prev{nullptr};
    for (int i = 0; i < length; i++) {
        after = temp->next;
        temp->next = prev;
        prev = temp;
        temp = after;
    }
}

LinkedList& LinkedList::concatenate(const LinkedList& ll) {
    std::shared_ptr<Node> temp {ll.head};
    for (int i = 0, n = ll.length; i < n; i++) {
        append(temp->val);
        temp = temp->next;
    }
    return *this;
}

LinkedList& LinkedList::operator+=(const LinkedList& ll) {
    return concatenate(ll);
}

std::unique_ptr<LinkedList> LinkedList::add(const LinkedList &ll1, const LinkedList &ll2) {
    std::unique_ptr<LinkedList> newList {std::make_unique<LinkedList>()};
    std::shared_ptr<Node> temp1 {ll1.head};
    std::shared_ptr<Node> temp2 {ll2.head};
    while (temp1 != nullptr) {
        if (temp2->next == nullptr && ll1.length != ll2.length) {
            newList->append(temp1->val + temp2->val);
            temp1 = temp1->next;
            break;
        }
        newList->append(temp1->val + temp2->val);
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    if (ll1.length > ll2.length) {
        while (temp1 != nullptr) {
            newList->append(temp1->val);
            temp1 = temp1->next;
        }
    } else {
        while (temp2 != nullptr) {
            newList->append(temp2->val);
            temp2 = temp2->next;
        }
    }
    return newList;
}

bool LinkedList::isPalindrome() {
    if (length < 1 || head->val != tail->val) return false;
    std::shared_ptr<Node> t1 {head->next};
    int j {2};
    for (int i = 0; i < length / 2; i++) {
        std::shared_ptr<Node> t2 {get(length - j)};
        if (t1->val != t2->val) return false;
        t1 = t1->next;
        j++;
    }
    return true;
}

// Naive method. Would be faster to use an unordered map
std::unique_ptr<LinkedList> LinkedList::intersection(LinkedList ll1, LinkedList ll2) {
    ll1.deleteDuplicates();
    ll2.deleteDuplicates();
    std::unique_ptr<LinkedList> newList {std::make_unique<LinkedList>()};
    std::shared_ptr<Node> t1 {ll1.head};
    for (int i = 0; i < ll1.length; i++) {
        std::shared_ptr<Node> t2 {ll2.head};
        for (int j = 0; j < ll2.length; j++) {
            bool alreadyPresent {false};
            if (t1->val == t2->val) {
                std::shared_ptr<Node> t3 {newList->head};
                for (int k = 0; k < newList->length; k++) {
                    if (t3->val == t1->val) {
                        alreadyPresent = true;
                        break;
                    }
                    t3 = t3->next;
                }
                if (!alreadyPresent) {
                    newList->append(t1->val);
                    break;
                }
            }
            t2 = t2->next;
        }
        t1 = t1->next;
    }
    return newList;
}


