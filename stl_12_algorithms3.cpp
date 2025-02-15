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
  std::vector<int> v = {3, 6, 2, 4, 1, 9, 7, 5, 0};
  PrintVec(v);
  std::sort(v.begin(),
            v.begin() + 5); // std::sort(start_iterator, end_iterator)
  PrintVec(v);
  // ****************************** sorting ******************************
  std::sort(v.begin(), v.end(), comp); // custom comparoator
  PrintVec(v);
  // **************************** partial sort ****************************
  /* std::partial_sort(RandomIt first, RandomIt middle, RandomIt last, Compare
  comp); The algorithm partially sorts the range [first, last), such that the
  elements in [first, middle) are sorted as if the entire range [first, last)
  were sorted. The elements in [middle, last) remain in an unspecified order.
  it is optimized for scenarios where you don’t need to sort an entire
  collection. Instead, it partially sorts the range, so that the elements in a
  specified subrange are in sorted order. constant space complexity, time
  complexity O(nlog(m)) n is length from first to last, m is length from first
  to middle */
  std::partial_sort(v.begin(), v.begin() + 3, v.end(),
                    [&](int a, int b) { return a > b; });
  PrintVec(v);
  // ****************** correcting the order of an element ***************
  /* std::nth_element(RandomIt first, RandomIt nth, RandomIt last, Compare
  comp); After calling std::nth_element, the element at position nth will be
  as if the entire range were sorted. Elements before nth will be less than or
  equal to nth. Elements after nth will be greater than or equal to nth. The
  elements are not guaranteed to be sorted before or after nth it is optimized
  for scenarios where you don’t need to sort an entire collection. Instead,
  you want an element from a certain index as if it is in its sorted position
  Time complexity O(n) */
  std::nth_element(v.begin(), v.begin() + 4, v.end(),
                   [&](int a, int b) { return a > b; });
  PrintVec(v);
  // *********************** partial sort and copy ***********************
  /* std::partial_sort_copy(InputIt first, InputIt last, OutputIt d_first,
  OutputIt d_last, Compare comp); performs sorting as well as copy the sorted
  elements to another structure without modifying the original sequence Time
  complexity O(nlog(m)), n size of Input, m size of Output */
  std::vector<int> v1(3); // we will take only 3 elements
  std::partial_sort_copy(v.begin(), v.end(), v1.begin(), v1.end(),
                         [&](int a, int b) { return a > b; });
  PrintVec(v1);

  return 0;
}