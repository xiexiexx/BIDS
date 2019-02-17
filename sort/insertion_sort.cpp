#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
void insertion_sort(vector<T>& V)
{
  for (size_t i = 1; i < V.size(); ++i)
  {
    auto key = V[i];
    auto position = lower_bound(V.begin(), V.begin() + i, key);
    for (auto iter = V.begin() + i; iter > position; --iter)
      *iter = *(iter - 1);
    *position = key;
  }
}

int main()
{
  vector<int> V = {2, 1, 3, 4, 5};
  insertion_sort(V);
  for (const auto& x : V)
    cout << x << ' ';
  cout << endl;
  return 0;
}
