#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename iterator>
iterator partition_Lomuto(iterator left, iterator position, iterator right)
{
  if (left <= position && position < right)
  {
    auto z = *position;
    swap(*position, *--right);
    for (position = left; position < right; ++position)
      if (*position < z)
        swap(*left++, *position);
    swap(*left, *right);
  }
  return left;
}

int main()
{
  vector<int> V = {5, 4, 3, 2, 1, 6, 7, 9, 0};
  auto pivot = partition_Lomuto(V.begin(), V.begin() + 2, V.end());
  cout << *pivot << endl;
  for (const auto& x : V)
    cout << x << ' ';
  return 0;
}
