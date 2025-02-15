#include <algorithm> // find
#include <iostream>
#include <set>           // set
#include <unordered_set> // unordered set

void PrintSet(std::set<int> s) {
  for (auto i : s)
    std::cout << i << " ";
  std::cout << "\n";
}

int main() {
  // stores everything unique and in sorted order, by default in ascending order
  std::set<int> s;
  /*
      set<DataType, greater<DataType>> s; // for descending order
  */

  /*  // for only sorted order but not unique elements
      multiset<int> ms;

      // its iterator also supports + operator
      auto it = ms.find(5);
      // it+1/it-1 are valid
  */

  /*
      // for unique but unsorted values
      unordered_set<int> us;
      // only lower_bound() and upper_bound() doesn't work for it. all
     operations will be of O(1)
  */

  s.insert(1); // O(log(n))
  s.insert(5);
  s.insert(3);
  s.insert(4);
  s.emplace(2);
  PrintSet(s);

  std::set<int>::iterator it1 = s.begin(), it2 = s.end();
  // remember since set is not a continuous memory, so it+1/it-1 is
  // hazardious, use ++/-- instead
  std::cout << *it1 << " " << *(++it1) << " " << *(++it1) << " " << *(--it2)
            << "\n";
  // auto is a smart keyword who automatically understand the datatype
  auto it = std::find(s.begin(), s.end(), 3);
  if (it != s.end()) {
    std::cout << *it << "\n";
  }
  auto it3 = s.find(3);
  if (it != s.end()) {
    s.erase(it); // O(log(n))
  }
  PrintSet(s);
  s.erase(1);
  PrintSet(s);

  s.insert(6);
  s.insert(1);
  s.insert(3);
  s.insert(7);
  s.insert(8);
  PrintSet(s);
  std::cout << s.size() << "\n";

  // Finds the first position where a value can be inserted without violating
  // order.
  auto it4 = s.lower_bound(2);
  // Finds the last position where a value can be inserted without violating
  // order.
  auto it5 = s.upper_bound(3);
  if (it4 != s.end())
    std::cout << *it4 << "\n";
  if (it5 != s.end())
    std::cout << *it5 << "\n";

  s.erase(++s.begin(), ++ ++ ++ ++s.begin());
  PrintSet(s);

  std::cout << s.count(8) << " " << s.count(9) << "\n";

  std::set<int> s1;
  s1.insert(10);
  s1.insert(30);
  s1.insert(20);

  PrintSet(s);
  s.swap(s1);
  PrintSet(s);

  std::cout << s.empty() << "\n";
  s.clear();
  std::cout << s.empty() << "\n";

  return 0;
}