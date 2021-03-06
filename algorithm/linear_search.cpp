#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout;
using std::endl;

// 线性查找: 数组版本.
template <typename T>
int linear_search_array(const T& key, const T data[], int n)
{
  for (int i = 0; i < n; ++i)
    if (data[i] == key)
      return i;         // 找到key, 返回位置信息.
  return n;             // 未找到key, 返回n.
}

// 线性查找: 向量版本.
template <typename T>
size_t linear_search_vector(const T& key, const vector<T>& data)
{
  for (size_t i = 0; i < data.size(); ++i)
    if (data[i] == key)
      return i;         // 找到key, 返回位置信息.
  return data.size();   // 未找到key, 返回data.size().
}

// 线性查找: 以迭代器方式实现.
template <typename T, typename IR>
IR linear_search_iterator(const T& key, IR left, IR right)
{
  // 巧妙利用短路表达式简化代码.
  while (left != right && *left != key)
    ++left;
  return left;
}

int main()
{
  const int m = 1000;
  int n = 5;
  int A[m] = {3, 2, 1, 4, 5};
  vector<string> V {"RSA", "Apple", "WWW", "While", "X"};
  cout << linear_search_array(1, A, n) << endl;
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
