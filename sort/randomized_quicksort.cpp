#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

// 最好使用C++17编译本程序.

random_device rd;
mt19937 gen(rd());

template <typename IR>
void quicksort(IR left, IR right)
{
  if (left + 1 < right)
  {
    uniform_int_distribution<> dis(0, right - left - 1);
    swap(*left, *(left + dis(gen)));
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
  vector<int> V = {2, 1, 3, 4, 5};
  srand(time(nullptr));
  quicksort(V.begin(), V.end());
  for (const auto& x : V)
    cout << x << ' ';
  cout << endl;
  return 0;
}
