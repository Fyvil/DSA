#include "queue.h"

int main() {
    Queue q {Queue({1,2,3,4,5})};
    q.enqueue({100,200,300,400,500});
    q.dequeue(5);
    q.print();
    q.details();
    return 0;
}
