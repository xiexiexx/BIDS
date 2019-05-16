#include <iostream>
#include <set>

using namespace std;

int main()
{
  set<int> S = {3, 2, 1, 4, 5};

  // 插入.
  S.insert(1);
  S.insert(7);

  // 查找与删除.
  auto iter = S.find(0);
  if (iter != S.end())
    S.erase(iter);
  iter = S.find(5);
  if (iter != S.end())
    S.erase(iter);
  S.erase(5);

  // 练习: 如何修改元素?

  // 迭代器位置.
  iter = S.begin();
  cout << *iter << endl;
  ++iter;
  cout << *iter << endl;
  --iter;
  cout << *iter << endl;

  // 遍历集合, 为简便计我们不讨论常量迭代器.
  for (auto iter = S.begin(); iter != S.end(); ++iter)
    cout << *iter << ' ';
  cout << endl;
  for (auto riter = S.rbegin(); riter != S.rend(); ++riter)
    cout << *riter << ' ';
  cout << endl;
  for (const auto& x : S)
    cout << x << ' ';
  cout << endl;
  
  return 0;
}
