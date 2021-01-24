#include <iostream>
#include <set>

using namespace std;

// 基于迭代器打印容器中所有元素.
template <typename IR>
void print_all(IR left, IR right)
{
  while (left != right)
    cout << *left++ << ' ';
  cout << endl;
}

// 基于范围的循环打印容器中所有元素.
template <typename T>
void print_all(const T& S)
{
  for (const auto& x : S)
    cout << x << ' ';
  cout << endl;
}

int main()
{
  set<int> S {3, 1, 2, 4, 5};
  print_all(S.begin(), S.end());
  print_all(S);

  // 初学者容易犯的错误:
  for (size_t i = 0; i < S.size(); ++i)
  {
    cout << *S.begin() << ' ';
    S.erase(S.begin());
  }
  cout << endl;
  // 应该直接以size()函数为准:
  while (S.size() > 0)  // !S.empty()
  {
    cout << *S.begin() << ' ';
    S.erase(S.begin());
  }
  cout << endl;
  // 最简单的做法:
  S.clear();

  return 0;
}
