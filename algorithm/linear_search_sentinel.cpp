#include <iostream>
#include <vector>
#include <string>

using namespace std;

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
int linear_search_vector_sentinel(const T& key, vector<T>& data)
{
  data.push_back(key);
  size_t i = 0;
  while (data[i] != key)
      ++i;
  data.pop_back();
  return i;
}

int main()
{
  const int n = 5;
  int A[n + 1] = {3, 2, 1, 4, 5, 0};
  vector<string> V = {"RSA", "Apple", "WWW", "While", "X"};
  V.reserve(2 * n);
  cout << linear_search_array_sentinel(9, A, n) << endl;
  string key = "Apple";
  cout << linear_search_vector_sentinel(key, V) << endl;
  return 0;
}
