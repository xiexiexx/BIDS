#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 注意不能写T类型在参数表里写typename vector<T>::iterator,
// 那样得配合一个T类型或者vector<T>类型的参数.
template <typename iterator>
void merge_sort(iterator L, iterator R, iterator AUX)
{
  if (L + 1 < R)
  {
    auto M = L + (R - L) / 2;
    merge_sort(L, M, AUX);
    merge_sort(M, R, AUX);
    // 如果使用inplace_merge会略慢.
    merge(L, M, M, R, AUX);
    copy(AUX, AUX + (R - L), L);
  }
}

int main()
{
  vector<int> V = {3, 2, 1, 4, 5};
  vector<int> A(V.size());
  merge_sort(V.begin(), V.end(), A.begin());
  for (const auto& x : V)
    cout << x << endl;
  return 0;
}
