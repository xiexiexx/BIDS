#include <iostream>
#include <set>
#include <map>

using namespace std;

template <typename K, typename V>
struct X {
  K key;
  V value;
  friend bool operator< (const X<K, V>& a, const X<K, V>& b)
  {
    return a.key < b.key;
  }
};

int main()
{
  set<X<string, double>> S;
  map<string, double> M;

  // 放入.
  S.insert({"K", 0.3});
  M.insert({"P1", 0.3});
  M["P2"] = 0.7;
  M["P3"] = 0.5;

  // 查找与删除.
  double x;
  if (S.find({"K", x}) != S.end())
    cout << "It exists!" << endl;
  auto iter = M.find("X");
  if (iter != M.end())
    M.erase(iter);
  M.erase("P1");

  // 修改值, 但是如果要修改键则需要删去再重新放入.
  iter = M.find("P2");
  iter->second = 0.6;
  M["P3"] = 0.4;

  // 迭代器位置.
  iter = M.begin();
  cout << iter->first << ", " << iter->second << endl;
  ++iter;
  cout << iter->first << ", " << iter->second << endl;
  --iter;
  cout << iter->first << ", " << iter->second << endl;

  // 遍历映射.
  for (auto iter = M.begin(); iter != M.end(); ++iter)
    cout << iter->first << ", " << iter->second << endl;
  for (auto riter = M.rbegin(); riter != M.rend(); ++riter)
    cout << riter->first << ", " << riter->second << endl;
  for (const auto& x : M)
    cout << x.first  << ", " << x.second << endl;
  return 0;
}
