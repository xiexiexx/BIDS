#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

// 最好使用C++17编译本程序.

random_device rd;
mt19937 gen(rd());

template <typename iterator>
void quicksort(iterator L, iterator R)
{
  if (L < R)
  {
    uniform_int_distribution<> dis(0, R - L - 1);
    auto P = *(L + dis(gen));;
    iterator LM = partition(L, R, [P](const auto& x) { return x < P; });
    iterator MR = partition(LM, R, [P](const auto& x) { return !(P < x); });
    quicksort(L, LM);
    quicksort(MR, R);
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
