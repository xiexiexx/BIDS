#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename iterator>
iterator partition_Lomuto(iterator L, iterator M, iterator R)
{
  if (L <= M && M < R)
  {
    auto P = *M;
    swap(*M, *--R);
    for (M = L; M < R; ++M)
      if (!(P < *M))
        swap(*L++, *M);
    swap(*L, *R);
  }
  return L;
}

int main()
{
  vector<int> V = {5, 4, 3, 2, 1, 6, 7, 9, 0};
  auto M = partition_Lomuto(V.begin(), V.begin() + 2, V.end());
  for (const auto& x : V)
    cout << x << ' ';
  cout << endl;
  return 0;
}
