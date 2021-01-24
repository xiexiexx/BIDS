#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  vector<int> V {2, 1, 3, 4, 5};
  int min = *min_element(V.begin(), V.end());
  auto M = partition(V.begin(), V.end(),
                     [min](const auto& x) { return x < min; });
  for (auto iter = V.begin(); iter != M; ++iter)
    cout << *iter << " ";
  cout << "* ";
  for (auto iter = M; iter != V.end(); ++iter)
    cout << *iter << " ";
  cout << endl;
  // result: * 2 1 3 4 5
  int max = *max_element(V.begin(), V.end());
  M = partition(V.begin(), V.end(),
                [max](const auto& x) { return !(max < x); });
  for (auto iter = V.begin(); iter != M; ++iter)
    cout << *iter << " ";
  cout << "* ";
  for (auto iter = M; iter != V.end(); ++iter)
    cout << *iter << " ";
  cout << endl;
  // result: 2 1 3 4 5 *
  return 0;
}
