#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 最好使用C++17编译本程序.
template <typename iterator>
void quicksort(iterator L, iterator R)
{
  if (L < R)
  {
    auto pivot = *L;
    auto M = partition(L, R, [pivot](const auto& x) { return x < pivot; });
    quicksort(L, M);
    quicksort(M + 1, R);
  }
}

int main()
{
  vector<int> V = {2, 1, 3, 4, 5};
  quicksort(V.begin(), V.end());
  for (const auto& x : V)
    cout << x << ' ';
  cout << endl;
  return 0;
}
