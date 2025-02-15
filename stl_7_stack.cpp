#include <iostream>
#include <stack>

void PrintStack(std::stack<int> s) {
  while (!s.empty()) {
    std::cout << s.top() << " ";
    s.pop();
  }
  std::cout << "\n";
}
int main() {
  std::stack<int> s;
  for (int i = 1; i <= 5; i++)
    s.push(i);

  std::cout << "The elements of the stack are:" << std::endl;
  PrintStack(s);

  std::cout << "The size of the stack: " << s.size() << std::endl;
  std::cout << "The top element of the queue: " << s.top() << std::endl;
  std::cout << "Pop the top element: " << std::endl;
  s.pop();
  PrintStack(s);

  std::stack<int> s1;
  for (int i = 1; i <= 5; i++)
    s1.push(i * 10);

  PrintStack(s);
  s.swap(s1);
  PrintStack(s);

  std::cout << s.empty() << "\n";
  return 0;
}