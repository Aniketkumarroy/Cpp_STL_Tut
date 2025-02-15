#include <algorithm> // find
#include <iostream>
#include <vector> // vector

void PrintVec(std::vector<int> v) {
  for (int i = 0; i < v.size(); i++)
    std::cout << v[i] << " ";
  std::cout << "\n";
}

int main() {
  // vector<anydatatype(simple or maybe complex)> v;
  std::vector<int> v;
  for (int i = 0; i < 5; i++)
    v.push_back(i);              // O(1)
  std::cout << v.size() << "\n"; // time complexity of v.size() is O(1)

  std::vector<int> v2(10); // initialize a vector of size 10 with all zeros
  PrintVec(v2);
  v2.push_back(7); // adding 7 at last
  PrintVec(v2);
  std::vector<int> v3(10, 3); // initialize a vector of size 10 with all 3
  PrintVec(v3);
  v3.pop_back(); // O(1), it pops the last elements
  PrintVec(v3);
  v3.emplace_back(5); // same as push_back() but faster

  std::vector<int> v6 = {1, 2, 3, 4, 5};
  std::vector<int>::iterator it = std::find(v6.begin(), v6.end(), 3);
  if (it != v6.end()) {
    v6.erase(it);
    PrintVec(v6);
  }
  std::cout << v6.at(0) << " " << v6[0] << "\n";

  std::vector<int> v4 = v3;  // copy, O(n)
  std::vector<int> v7(v3);   // copy, O(n)
  std::vector<int> &v5 = v3; // reference, O(1)

  // auto is a smart keyword who automatically understand the datatype
  auto it1 = v6.begin(), it2 = v6.end();
  std::cout << *it1 << " " << *(it1 + 1) << " " << it1[2] << " " << *(--it2)
            << "\n";

  std::cout << "###############################\n";

  std::vector<int> v8 = {10, 20, 30, 40, 50, 60, 70, 80, 90};
  PrintVec(v8);
  v8.erase(v8.begin() + 1, v8.begin() + 4); // erases [start, end)
  PrintVec(v8);
  auto it3 = std::find(v8.begin(), v8.end(), 90);
  v8.erase(it3); // 10 20 40 50 60 70 80 90
  PrintVec(v8);
  v8.insert(v8.begin() + 1, 6); // (position, value), O(n)
  PrintVec(v8);
  std::vector<int> v9(3, 7);
  v8.insert(v8.begin() + 1, v9.begin(), v9.end()); // (position, value)
  PrintVec(v8);

  v6.swap(v8); // O(1)
  PrintVec(v8);
  std::cout << v8.empty() << "\n";
  v8.clear(); // O(n)
  std::cout << v8.empty() << "\n";
  return 0;
}