#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 最好使用C++17编译本程序.

template <typename iterator>
void quickselect(iterator left, iterator right, size_t k)
{
  if (left + k < right)
  {
    auto z = *left;
    iterator pivot =
      partition(left + 1, right, [z](const auto& x) { return x < z; }) - 1;
    size_t d = pivot - left;
    swap(*left, *pivot);
    if (d == k)
      return;
    if (k < d)
      quickselect(left, pivot, k);
    else
      quickselect(pivot + 1, right, k - d - 1);
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
