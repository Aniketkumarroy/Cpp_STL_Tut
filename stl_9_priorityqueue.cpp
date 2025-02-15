#include <iostream>
#include <queue>

void PrintPriorityqueue(std::priority_queue<int> pq) {
  // priority_queue<int> pq2=pq;
  while (!pq.empty()) {
    std::cout << pq.top() << " ";
    pq.pop();
  }
  std::cout << "\n";
}
int main() {
  std::priority_queue<int> pq; // by default it makes a max heap data structure

  /*

      // for using a min heap datastructure
      priority_queue<int, vector<int>, greater<int>> pq;

  */

  pq.push(5); // O(log(n))
  pq.push(1);
  pq.push(4);
  pq.push(3);
  pq.push(2);

  std::cout << "The elements of the priority queue are:" << std::endl;
  PrintPriorityqueue(pq);

  std::cout << "The size of the priority queue: " << pq.size() << std::endl;
  std::cout << "The top element of the priority queue: " << pq.top()
            << std::endl; // O(1)
  std::cout << "Pop the top element: " << std::endl;
  pq.pop(); // O(log(n))
  PrintPriorityqueue(pq);

  std::priority_queue<int> pq1;
  pq1.push(10);
  pq1.push(50);
  pq1.push(30);
  pq1.push(40);
  pq1.push(20);

  PrintPriorityqueue(pq);
  pq.swap(pq1);
  PrintPriorityqueue(pq);

  std::cout << pq.empty() << "\n";
  return 0;
}