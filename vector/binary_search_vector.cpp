#include <iostream>
#include <vector>

using namespace std;

// 为了简便起见, 没有使用vector<T>::const_iterator.
template <typename T>
bool binary_search_vector(const T& key, typename vector<T>::iterator data,
                          size_t N)
{
  size_t low = 0;
  size_t high = N;
  while (low < high)
  {
    size_t mid = low + (high - low) / 2;
    if (key < *(data + mid))		// 小则去前半部分继续查找.
      high = mid;
    else if (*(data + mid) < key)	// 大则去后半部分继续查找.
      low = mid + 1;
    else
      return true;
  }
  return false;
}

// 使用迭代器, 描述更清晰, 而且还可支持数组.
template <typename T, typename iterator>
bool binary_search_iterator(const T& key, iterator L, iterator R)
{
  while (L < R)
  {
    iterator M = L + (R - L) / 2;
    if (key < *M)       // 小则去前半部分继续查找.
      R = M;
    else if (*M < key)  // 大则去后半部分继续查找.
      L = M + 1;
    else
      return true;
  }
  return false;
}

int main()
{
  vector<int> v = {1, 2, 3, 4, 5};
  cout << binary_search_vector(2, v.begin(), 5) << endl;
  cout << binary_search_vector(0, v.begin(), 5) << endl;
  cout << binary_search_vector(2, v.begin() + 2, 3) << endl;
  cout << binary_search_vector(0, v.begin(), 0) << endl;
  cout << binary_search_iterator(2, v.begin(), v.end()) << endl;
  cout << binary_search_iterator(0, v.begin(), v.end()) << endl;
  cout << binary_search_iterator(2, v.begin() + 2, v.end()) << endl;
  cout << binary_search_iterator(0, v.begin(), v.end()) << endl;
  return 0;
}
