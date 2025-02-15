#include <algorithm>
#include <iostream>
#include <vector>

void PrintVec(std::vector<int> v) {
  for (int i = 0; i < v.size(); i++)
    std::cout << v[i] << " ";
  std::cout << "\n";
}

bool comp(int e1, int e2) {
  if ((e1 * e1 - 4 * e1) < (e2 * e2 - 4 * e2))
    return true;
  return false;
}

int main() {
  // *********************** counting no. of set bits ***********************
  std::cout << __builtin_popcount(7) << "\n"; // returns the no. of set bits
  /*
      for long long use __builtin_popcountll() instead of __builtin_popcount()
  */
  std::cout << __builtin_popcount(5) << "\n";
  // ***************************** permutation *****************************
  std::string s = "231";
  do {
    std::cout << s << " ";
  } while (std::next_permutation(s.begin(), s.end()));
  std::cout << "\n";

  s = "231";
  do {
    std::cout << s << " ";
  } while (std::prev_permutation(s.begin(), s.end()));
  std::cout << "\n";

  std::sort(s.begin(), s.end());
  do {
    std::cout << s << " ";
  } while (std::next_permutation(s.begin(), s.end()));
  std::cout << "\n";
  // ***************************** min and max *****************************
  std::vector<int> v = {3, 6, 2, 4, 1, 9, 7, 5, 0};
  auto it1 = std::max_element(v.begin(), v.end());
  auto it2 = std::min_element(v.begin(), v.end());

  std::cout << "max element " << *it1 << "\n";
  std::cout << "min element " << *it2 << "\n";
  // ******************************** find ********************************
  std::cout << "############## find ##############\n";
  auto is_even = [](int n) { return n % 2 == 0; };

  auto it3 = std::find_if(v.begin(), v.end(), is_even);
  if (it3 != v.end())
    std::cout << "first even number " << *it3 << "\n";
  auto it4 = std::find_if_not(v.begin(), v.end(), is_even);
  if (it4 != v.end())
    std::cout << "first odd number " << *it4 << "\n";

  std::vector<int> v1 = {1, 2, 5, 5, 7, 9, 9};
  auto it5 = std::adjacent_find(v1.begin(), v.end());
  if (it5 != v1.end())
    std::cout << "Two adjacent elements are " << *it5 << " and " << *(++it5)
              << "\n";
  auto cmp = [](int a, int b) { return (b - a) == 2; };
  it5 = std::adjacent_find(v1.begin(), v.end(), cmp);
  if (it5 != v1.end())
    std::cout << "Two adjacent elements are " << *it5 << " and " << *(++it5)
              << "\n";
  // ********************************* count *********************************
  std::cout << "############## count ##############\n";
  int n = std::count(v.begin(), v.end(), 7);
  std::cout << "no. of occurace of 7 is " << n << "\n";
  n = std::count_if(v.begin(), v.end(), is_even);
  std::cout << "no. of even is " << n << "\n";
  // ********************************* index *********************************
  std::cout << "############## index ##############\n";
  auto it6 = std::find(v.begin(), v.end(), 0);
  if (it6 != v.end()) {
    std::cout << "0 exist at index " << std::distance(v.begin(), it6) << "\n";
  }
  return 0;
}