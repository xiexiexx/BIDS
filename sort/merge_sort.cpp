#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 注意不能设定T类型然后在参数表里全用typename vector<T>::iterator,
// 那样得在参数表里加入一个T类型或者vector<T>类型的参数,
// 否则编译器无法仅凭vector<T>::iterator回溯获知T的类型.
template <typename IR>
void merge_sort(IR left, IR right, IR aux)
{
  if (left + 1 < right)
  {
    IR middle = left + (right - left) / 2;
    merge_sort(left, middle, aux);
    merge_sort(middle, right, aux);
    // 如果使用inplace_merge(left, middle, right);会略慢.
    merge(left, middle, middle, right, aux);
    copy(aux, aux + (right - left), left);
  }
}

int main()
{
  vector<int> V {3, 2, 1, 4, 5};
  vector<int> A(V.size());
  merge_sort(V.begin(), V.end(), A.begin());
  for (const auto& x : V)
    cout << x << endl;
  return 0;
}
