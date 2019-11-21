#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 最好使用C++17编译本程序.

template <typename iterator>
void quickselect(iterator left, iterator right, size_t k)
{
  while (left + k < right)
  {
    auto z = *left;
    iterator pivot =
      partition(left + 1, right, [z](const auto& x) { return x < z; }) - 1;
    swap(*left, *pivot);
    size_t d = pivot - left;
    if (d == k)
      return;
    if (k < d)
      right = pivot;
    else
    {
      left = pivot + 1;
      k -= d + 1;
    }
  }
}

// 可考虑将上述程序改为随机化版本.

int main()
{
  vector<int> V = {5, 4, 3, 2, 1, 6, 7, 9, 0};
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
