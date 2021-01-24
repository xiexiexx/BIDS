#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 最好使用C++17编译本程序.

template <typename IR>
void quicksort(IR left, IR right)
{
  if (left + 1 < right)
  {
    auto z = *left;
    IR pivot = 
      partition(left + 1, right, [z](const auto& x) { return x < z; }) - 1;
    swap(*left, *pivot);
    quicksort(left, pivot);
    quicksort(pivot + 1, right);
  }
}

int main()
{
  vector<int> V {2, 1, 3, 4, 5};
  quicksort(V.begin(), V.end());
  for (const auto& x : V)
    cout << x << ' ';
  cout << endl;
  return 0;
}
