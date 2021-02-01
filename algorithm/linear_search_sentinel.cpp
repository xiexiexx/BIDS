#include <iostream>
#include <vector>
#include <string>
#include <list>

using std::vector;
using std::string;
using std::list;
using std::cout;
using std::endl;

// 线性查找: 带有哨兵的数组版本. 要求data的长度大于n.
template <typename T>
int linear_search_array_sentinel(const T& key, T data[], int n)
{
  data[n] = key;
  int i = 0;
  while (data[i] != key)
      ++i;
  return i;
}

// 线性查找: 带有哨兵的向量版本.
// 要求向量容量data.capacity()大于data.size().
template <typename T>
size_t linear_search_vector_sentinel(const T& key, vector<T>& data)
{
  data.push_back(key);
  size_t i = 0;
  while (data[i] != key)
      ++i;
  data.pop_back();
  return i;
}

// 线性查找: 带有哨兵的迭代器方式实现. 要求末尾单独留有空位.
template <typename T, typename IR>
IR linear_search_iterator_sentinel(const T& key, IR left, IR right)
{
  *right = key;
  while (*left != key)
    ++left;
  return left;
}

int main()
{
  const int n = 5;
  int A[n + 1] = {3, 2, 1, 4, 5, 0};
  vector<string> V {"RSA", "Apple", "WWW", "While", "X"};
  string sentinel;
  list<string> L {"RSA", "Apple", "WWW", "While", "X", sentinel};
  V.reserve(2 * n);
  cout << linear_search_array_sentinel(9, A, n) << endl;
  string key = "Apple";
  cout << linear_search_vector_sentinel(key, V) << endl;
  // 如果要提高效率, 库函数内部其实可用哑结点位置L.end()直接放置哨兵.
  // 另外, 使用这种方式要保证L非空, 否则--L.end()会导致出错.
  auto iter = linear_search_iterator_sentinel(key, L.begin(), --L.end());
  if (iter != L.end())
    cout << *iter << endl;
  return 0;
}
