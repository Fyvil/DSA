#include <iostream>
#include "stack.h"


int main() {
    Stack s{Stack({1, 2, 3, 4, 5})};
    s.print();
    s.details();
    return 0;
}
