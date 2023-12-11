#include "queue.h"

int main() {
    Queue q {Queue({1,2,3,4,5})};
    q.enqueue({100,200,300,400,500});
    q.dequeue(2);
    std::cout << q.getFirst() << std::endl;
    q.print();
    q.details();
    return 0;
}
