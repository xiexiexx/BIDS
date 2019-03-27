#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  vector<int> V = {5, 4, 3, 2, 1, 6, 7, 9, 0};
  size_t k;
  cin >> k;
  nth_element(V.begin(), V.begin() + k, V.end());
  for (const auto& x : V)
    cout << x << ' ';
  cout << endl;
  return 0;
}
