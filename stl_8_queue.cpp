#include <iostream>
#include <queue>

void PrintQueue(std::queue<int> q1) {
  std::queue<int> q2 = q1;
  while (!q2.empty()) {
    std::cout << q2.front() << " ";
    q2.pop();
  }
  std::cout << "\n";
}
int main() {
  std::queue<int> q;
  for (int i = 1; i <= 5; i++)
    q.push(i);

  std::cout << "The elements of the queue are:" << std::endl;
  PrintQueue(q);

  std::cout << "The size of the queue: " << q.size() << std::endl;
  std::cout << "The front element of the queue: " << q.front() << std::endl;
  std::cout << "The last element of the queue: " << q.back() << std::endl;
  std::cout << "Pop the front element: " << std::endl;
  q.pop();
  PrintQueue(q);

  std::queue<int> q1;
  for (int i = 1; i <= 5; i++)
    q1.push(i * 10);

  PrintQueue(q);
  q.swap(q1);
  PrintQueue(q);

  std::cout << q.empty() << "\n";
  return 0;
}