#include "stack.h"
#include <memory>
#include <vector>

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5};
  std::unique_ptr<Stack> s{std::make_unique<Stack>(vec)};
  s->print();
  s->details();
  return 0;
}
