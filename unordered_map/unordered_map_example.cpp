#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
  unordered_map<string, double> M;

  // 放入.
  M.insert({"P1", 0.3});
  M["P2"] = 0.7;
  M["P3"] = 0.5;

  // 查找与删除.
  auto iter = M.find("X");
  if (iter != M.end())
    M.erase(iter);
  M.erase("P1");

  // 修改值, 但是如果要修改键则需要删去再重新放入.
  iter = M.find("P2");
  iter->second = 0.6;
  M["P3"] = 0.4;

  // 迭代器位置没有太大的意义, 而且只有++无--, 要特别注意.
  iter = M.begin();
  cout << iter->first << ", " << iter->second << endl;
  ++iter;
  cout << iter->first << ", " << iter->second << endl;

  // 遍历映射. 注意不存在逆向遍历.
  for (auto iter = M.begin(); iter != M.end(); ++iter)
    cout << iter->first << ", " << iter->second << endl;
  for (const auto& x : M)
    cout << x.first  << ", " << x.second << endl;

  return 0;
}
