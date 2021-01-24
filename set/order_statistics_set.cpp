#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
  set<int> S {3, 2, 1, 4, 5};
  int k;
  cin >> k;
  if (k < 1 || k > S.size())
    cout << "超出范围!" << endl;
  else
  {
    // 第一种方法:
    auto iter = S.begin();
    for (int i = 0; i < k - 1; ++i)
      ++iter;
    cout << *iter << endl;
    // 第二种方法(较慢):
    vector<int> V;
    // 预留k - 1个元素空间.
    V.reserve(k - 1);
    // 删除S中的前k - 1个元素并暂存到V中.
    for (int i = 0; i < k - 1; ++i)
    {
      V.push_back(*S.begin());
      S.erase(S.begin());
    }
    cout << *S.begin() << endl;
    // 将前k - 1个元素放回S中, 也可对V使用基于范围的for循环.
    // 最简单的方式是直接使用:
    // S.insert(V.begin(), V.end());
    for (size_t i = 0; i < V.size(); ++i)
      S.insert(V[i]);
  }
  return 0;
}
