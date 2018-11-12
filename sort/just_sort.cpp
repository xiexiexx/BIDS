#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
  const int N = 5;
  int a[N] = {2, 5, 3, 1, 4};

  // 从小到大排序.
  sort(a, a + N);
  for (int i = 0; i < N; ++i)
    cout << a[i] << " ";
  cout << endl;

  // 使用函数对象greater<int>()进行从大到小排序.
  sort(a, a + N, greater<int>());
  // 有的编译器可能需要functional头文件.
  for (int i = 0; i < N; ++i)
    cout << a[i] << " ";
  cout << endl;

  // 对字符串排序.
  string b[N] = {"www", "algorithm", "racer", "text", "wait"};
  sort(b, b + N);
  for (int i = 0; i < N; ++i)
    cout << b[i] << endl;
  sort(b, b + N, greater<string>());
  for (int i = 0; i < N; ++i)
    cout << b[i] << endl;

  // 对向量排序.
  vector<string> v = {"www", "algorithm", "racer", "text", "wait"};
  // 从小到大排序.
  sort(v.begin(), v.end());
  // 使用函数对象greater<int>()进行从大到小排序.
  sort(v.begin(), v.end(), greater<string>());
  // 使用迭代器打印v中所有元素.
  for (auto iter = v.begin(); iter != v.end(); ++iter)
    cout << *iter << endl;
  // 使用逆向迭代器进行从大到小排序.
  sort(v.rbegin(), v.rend());
  // 使用基于范围的for循环打印v中所有元素.
  for (const string& x : v)
    cout << x << endl;

  return 0;
}
