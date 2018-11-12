#include <iostream>
#include <set>

using namespace std;

int main()
{
  set<int> S = {3, 2, 1, 4, 5};

  // 放入.
  S.insert(1);
  S.insert(7);

  // 查找与删除.
  auto iter = S.find(0);
  if (iter != S.end())
    S.erase(iter);
  iter = S.find(5);
  if (iter != S.end())
    S.erase(iter);

  // 练习: 如何修改元素?

  // 迭代器位置.
  iter = S.begin();
  cout << *iter << endl;
  ++iter;
  cout << *iter << endl;
  --iter;
  cout << *iter << endl;

  // 遍历集合.
  for (auto iter = S.cbegin(); iter != S.cend(); ++iter)
    cout << *iter << endl;
  for (auto riter = S.crbegin(); riter != S.crend(); ++riter)
    cout << *riter << endl;
  for (const auto& x : S)
    cout << x << endl;

  return 0;
}
