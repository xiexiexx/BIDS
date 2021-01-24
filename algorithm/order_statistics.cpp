#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 最好使用C++17编译本程序.

// 可思考将本程序改为随机化版本.
template <typename IR>
void quickselect(IR left, IR right, size_t k)
{
  if (left + k >= right)
    return;
  while (true)
  {
    auto z = *left;
    IR pivot =
      partition(left + 1, right, [z](const auto& x) { return x < z; }) - 1;
    swap(*left, *pivot);
    size_t d = pivot - left;
    if (d == k)
      return;
    if (d < k)
    {
      // 考虑到d有可能为0, 但d与k不等, 所以将枢纽元计入防止无限循环.
      left = pivot + 1;
      k -= d + 1;
    }
    else
      right = pivot;
  }
}

int main()
{
  vector<int> V {5, 4, 3, 2, 1, 6, 7, 9, 0};
  vector<int> C(V.begin(), V.end());
  size_t k;
  cin >> k;
  nth_element(V.begin(), V.begin() + k, V.end());
  for (const auto& x : V)
    cout << x << ' ';
  cout << endl;
  quickselect(C.begin(), C.end(), k);
  for (const auto& x : C)
    cout << x << ' ';
  return 0;
}
