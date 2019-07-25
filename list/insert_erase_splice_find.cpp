#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
  list<int> L = {-2, -1, 1, 2};
  auto iter = L.begin();
  while (iter != L.end() && *iter < 0)
    ++iter;
  L.insert(iter, 0);
  cout << *iter << endl;
  iter = L.begin();
  while (iter != L.end())
    if (*iter > 0)
      iter = L.erase(iter);
    else
      ++iter;
  list<int> R = {-5, -4, -3};
  L.splice(L.begin(), R, ++R.begin(), R.end());
  for (const auto& x : L)
    cout << x << endl;
  iter = find(L.begin(), L.end(), 0);
  if (iter != L.end())
    L.erase(iter);
  return 0;
}
