#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
void print_all(const T& S)
{
  for (const auto& x : S)
    cout << x << ' ';
  cout << endl;
}

int main()
{
  int key;

  // 有序向量.
  vector<int> SV {1, 3, 6, 6, 8, 9};
  // 查找元素.
  cin >> key;
  auto iter = lower_bound(SV.begin(), SV.end(), key);
  cout << iter - SV.begin() << endl;
  iter = upper_bound(SV.begin(), SV.end(), key);
  cout << iter - SV.begin() << endl;
  // 插入新元素.
  key = 0;
  SV.insert(upper_bound(SV.begin(), SV.end(), key), key);
  // 删除重复元素的最后一个. 思考: 如何删除第一个?
  key = 6;
  // 如果存在则删除.
  if (binary_search(SV.begin(), SV.end(), key))
  {
    iter = upper_bound(SV.begin(), SV.end(), key);
    SV.erase(--iter);
  }
  // 查找重复key所在的区间range, 区间为[range.first, range.second).
  auto range = equal_range(SV.begin(), SV.end(), key);
  // 删除整个range区间的元素.
  SV.erase(range.first, range.second);
  // 打印.
  print_all(SV);

  // 无序向量.
  vector<int> UV {9, 6, 1, 3, 8, 6};
  // 插入新元素.
  key = 0;
  UV.push_back(key);
  // 删除重复元素的最后一个. 思考: 如何删除第一个?
  key = 6;
  // 注意这里得使用逆向迭代器, 而不能使用正向迭代器iter.
  auto riter = find(UV.rbegin(), UV.rend(), key);
  // 如果存在则删除.
  if (riter != UV.rend())
  {
    *riter = UV.back();
    UV.pop_back();
  }
  // 打印.
  print_all(UV);

  return 0;
}
