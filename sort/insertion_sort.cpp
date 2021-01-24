#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

template <typename T>
void insertion_sort_vector(vector<T>& V)
{
  for (size_t i = 1; i < V.size(); ++i)
  {
    T current = V[i];
    auto position = lower_bound(V.begin(), V.begin() + i, current);
    for (auto iter = V.begin() + i; iter > position; --iter)
      *iter = *(iter - 1);
    *position = current;
  }
}

template <typename T>
void insertion_sort_list(list<T>& L)
{
  for (auto iter = L.begin(); iter != L.end(); ++iter)
  {
    auto position = L.begin();
    while (position != iter && *position < *iter)
      ++position;
    L.splice(position, L, iter);
  }
}

int main()
{
  vector<int> V {2, 1, 3, 4, 5};
  list<int> L(V.begin(), V.end());
  insertion_sort_vector(V);
  for (const auto& x : V)
    cout << x << ' ';
  cout << endl;
  insertion_sort_list(L);
  for (const auto& x : L)
    cout << x << ' ';
  cout << endl;
  return 0;
}
