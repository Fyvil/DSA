#include "linkedlist.cpp"
int main() {
  LinkedList<std::string> sll{LinkedList<std::string>(
      {"prajit", "praveen", "priya", "deepa", "kavitha", "subbu"})};
  auto sll2{sll};
  sll2.append("abc");
  std::cout << sll2.pop(1) << std::endl;
  sll2.print();
  sll2.details();
  return 0;
}
