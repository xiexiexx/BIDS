#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int key;

  // 有序向量.
  vector<int> sv = {1, 3, 6, 6, 8, 9};
  // 插入新元素.
  key = 0;
  auto iter_sv = lower_bound(sv.begin(), sv.end(), key);
  sv.insert(iter_sv, key);
  // 删除元素(重复元素的最后一个). 思考: 如何删除第一个?
  key = 6;
  // 如果存在则删除.
  if (binary_search(sv.begin(), sv.end(), key))
  {
    iter_sv = upper_bound(sv.begin(), sv.end(), key);
    --iter_sv;
    sv.erase(iter_sv);
  }
  // 查找重复key所在的区间range, 区间为[range.first, range.second).
  auto range = equal_range(sv.begin(), sv.end(), key);
  // 删除整个range区间的元素.
  sv.erase(range.first, range.second);
  // 打印.
  for (const auto& x : sv)
    cout << x << " ";
  cout << endl;

  // 无序向量.
  vector<int> usv = {9, 6, 1, 3, 8, 6};
  // 插入新元素.
  key = 0;
  usv.push_back(key);
  // 删除元素(重复元素的第一个). 思考: 如何删除最后一个?
  key = 6;
  auto iter_usv = find(usv.begin(), usv.end(), key);
  // 如果存在则删除.
  if (iter_usv != usv.end())
  {
    *iter_usv = usv.back();
    usv.pop_back();
  }
  // 打印.
  for (auto& x : usv)
    cout << x << " ";
  cout << endl;

  return 0;
}
