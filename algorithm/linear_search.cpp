#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T>
int linear_search_array(const T& key, const T data[], int N)
{
  for (int pos = 0; pos < N; ++pos)
    if (data[pos] == key)
      return pos;
  return N;
}

// 要求data的长度大于N.
template <typename T>
int linear_search_array_sentinel(const T& key, T data[], int N)
{
  data[N] = key;
  int pos = 0;
  while (data[pos] != key)
      ++pos;
  return pos;
}

template <typename T>
size_t linear_search_vector(const T& key, const vector<T>& data)
{
  for (size_t pos = 0; pos < data.size(); ++pos)
    if (data[pos] == key)
      return pos;
  return data.size();
}

template <typename T, typename iterator>
iterator linear_search_iterator(const T& key, iterator L, iterator R)
{
  while (L != R && *L != key)
    ++L;
  return L;
}

// 原始写法有点冗长.
/*
  while (L != R)
  {
    if (*L == key)
      return L;
    ++L;
  }
  return L;
*/
// 另外, 不要过度追求简洁而出错, 从而返回不正确的迭代器位置.
/*
  if (*L++ == key)
    return L;
*/

int main()
{
  const int N = 5;
  const int L = N + 1;
  int A[L] = {3, 2, 1, 4, 5, 0};
  vector<string> V = {"RSA", "Apple", "WWW"};
  cout << linear_search_array(1, A, N) << endl;
  cout << linear_search_array_sentinel(9, A, N) << endl;
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
