#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T>
int linear_search_array(const T& key, const T data[], int n)
{
  for (int i = 0; i < n; ++i)
    if (data[i] == key)
      return i;
  return n;
}

// 要求data的长度大于n.
template <typename T>
int linear_search_array_sentinel(const T& key, T data[], int n)
{
  data[n] = key;
  int i = 0;
  while (data[i] != key)
      ++i;
  return i;
}

template <typename T>
size_t linear_search_vector(const T& key, const vector<T>& data)
{
  for (size_t i = 0; i < data.size(); ++i)
    if (data[i] == key)
      return i;
  return data.size();
}

template <typename T, typename iterator>
iterator linear_search_iterator(const T& key, iterator left, iterator right)
{
  while (left != right && *left != key)
    ++left;
  return left;
}

/*
 * 原始写法有点冗长.
 * while (left != right)
 * {
 *   if (*left == key)
 *     return left;
 *   ++left;
 * }
 * return left;
 * 另外, 不要过度追求简洁而出错, 从而返回不正确的迭代器位置.
 * if (*left++ == key)
 *   return left;
 */

int main()
{
  const int n = 5;
  int A[n + 1] = {3, 2, 1, 4, 5, 0};
  vector<string> V = {"RSA", "Apple", "WWW"};
  cout << linear_search_array(1, A, n) << endl;
  cout << linear_search_array_sentinel(9, A, n) << endl;
  string key = "Apple";
  cout << linear_search_vector(key, V) << endl;
  key = "Algorithm";
  auto iter = linear_search_iterator(key, V.begin(), V.end());
  if (iter == V.end())
    cout << "Not Found!" << endl;
  else
    cout << *iter << endl;
  return 0;
}
