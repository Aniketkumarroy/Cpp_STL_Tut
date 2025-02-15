#include <algorithm>
#include <deque>
#include <iostream>

void PrintDeque(std::deque<int> dq) {
  for (auto i : dq)
    std::cout << i << " ";
  std::cout << "\n";
}

int main() {
  std::deque<int> dq;

  dq.push_back(1); // O(1)
  dq.push_back(2);
  dq.emplace_back(3);
  PrintDeque(dq);

  // since it uses a doubly linkedlist, pushing and popping in front is handy
  dq.push_front(4); // O(1)
  dq.push_front(5);
  dq.emplace_front(6);
  PrintDeque(dq);

  // random access is available, it is a continuous memory
  std::cout << dq[0] << " \n";

  std::cout << dq.front() << " " << dq.back() << "\n";
  // auto is a smart keyword who automatically understand the datatype
  std::deque<int>::iterator it1 = dq.begin(), it2 = dq.end();
  std::cout << *it1 << " " << it1[1] << " " << *(++it1) << " " << *(++it1)
            << " " << *(--it2) << "\n";

  dq.insert(dq.begin() + 1, 8);
  PrintDeque(dq);

  std::deque<int> dq1;
  dq1.emplace_back(10);
  dq1.emplace_back(30);
  dq1.emplace_front(20);
  dq.insert(dq.begin() + 1, dq1.begin(), dq1.end());
  PrintDeque(dq);
  std::cout << dq.size() << "\n";

  auto it = std::find(dq.begin(), dq.end(), 3);
  if (it != dq.end()) {
    dq.erase(it);
    PrintDeque(dq);
  }

  dq.erase(dq.begin() + 1, dq.begin() + 4);
  PrintDeque(dq);

  dq.swap(dq1);
  PrintDeque(dq);
  std::cout << dq.empty() << "\n";
  dq.clear();
  std::cout << dq.empty() << "\n";

  return 0;
}