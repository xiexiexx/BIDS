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
  if (L + 1 < R)
  {
    uniform_int_distribution<> dis(0, R - L - 1);
    swap(*L, *(L + dis(gen)));
    auto P = *L;
    iterator M = --partition(L + 1, R, [P](const auto& x) { return x < P; });
    swap(*L, *M);
    quicksort(L, M);
    quicksort(M + 1, R);
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
  if (1 < 1)
    cout << "Y";
  return 0;
}
