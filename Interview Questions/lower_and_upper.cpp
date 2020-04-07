#include <iostream>
#include <vector>

using namespace std;

template <typename T, typename iterator>
iterator lower(const T& key, iterator left, iterator right)
{
  while (left < right)
  {
    iterator middle = left + (right - left) / 2;
    if (*middle < key)
      left = middle + 1;
    else
      right = middle;
  }
  return left;
}

template <typename T, typename iterator>
iterator upper(const T& key, iterator left, iterator right)
{
  while (left < right)
  {
    iterator middle = left + (right - left) / 2;
    if (key < *middle)
      right = middle;
    else
      left = middle + 1;
  }
  return left;
}

int main()
{
  vector<int> V = {1, 2, 2, 2, 3};
  cout << lower(2, V.begin(), V.end()) - V.begin() << endl;
  cout << upper(2, V.begin(), V.end()) - V.begin() << endl;
  return 0;
}
