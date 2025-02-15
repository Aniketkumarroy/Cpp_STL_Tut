#include <iostream>
#include <string>  // std::string
#include <utility> // std::pair

int main() {
  // pair<anydatatype, anydatatype> p;
  std::pair<int, std::string> p;
  p = std::make_pair(2, "abc");
  std::cout << p.first << "\t" << p.second << "\n"; // 2   abc
  p = {3, "xyz"};
  std::cout << p.first << "\t" << p.second << "\n"; // 3	xyz

  std::pair<int, std::string> p1 = p; // copy of p will go to p1
  p1.first = 5;
  std::cout << p.first << "\t" << p.second << "\n"; // 3  xyz
  std::pair<int, std::string> &p2 = p;              // reference will go in p2
  p2.first = 5;
  std::cout << p.first << "\t" << p.second << "\n"; // 5  xyz

  std::pair<int, std::string> pa[5]; // array of pairs
  pa[0] = {0, "zero"};
  pa[1] = {1, "one"};
  pa[2] = {2, "two"};
  pa[3] = {3, "three"};
  pa[4] = {4, "four"};

  for (int i = 0; i < 5; i++)
    std::cout << pa[i].first << " " << pa[i].second << "\n";

  std::cout << "\n";
  std::swap(pa[0], pa[4]); // swapping
  for (int i = 0; i < 5; i++)
    std::cout << pa[i].first << " " << pa[i].second << "\n";

  std::cout << "\n";
  std::cout << pa->first << "\n";       // 4
  std::cout << (pa + 1)->first << "\n"; // 1

  return 0;
}
