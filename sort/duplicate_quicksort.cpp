#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

// 最好使用C++17编译本程序.

random_device rd;
mt19937 gen(rd());

template <typename iterator>
void quicksort(iterator left, iterator right)
{
  if (left + 1 < right)
  {
    uniform_int_distribution<> dis(0, right - left - 1);
    auto z = *(left + dis(gen));;
    iterator lr = partition(left, right, [z](const auto& x) { return x < z; });
    iterator rl = partition(lr, right, [z](const auto& x) { return !(z < x); });
    quicksort(left, lr);
    quicksort(rl, right);
  }
}

int main()
{
  vector<int> V = {2, 1, 2, 3, 4, 5, 3, 4, 5};
  srand(time(nullptr));
  quicksort(V.begin(), V.end());
  for (const auto& x : V)
    cout << x << ' ';
  cout << endl;
  return 0;
}
