#include <iostream>
#include <vector>

using namespace std;

template <typename T, typename IR>
IR lower(const T& key, IR left, IR right)
{
  while (left < right)
  {
    IR middle = left + (right - left) / 2;
    if (*middle < key)
      left = middle + 1;
    else
      right = middle;
  }
  return left;
}

template <typename T, typename IR>
IR upper(const T& key, IR left, IR right)
{
  while (left < right)
  {
    IR middle = left + (right - left) / 2;
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
