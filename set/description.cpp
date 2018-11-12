#include <iostream>
#include <set>
#include <vector>
#include <string>

using namespace std;

int main()
{
  // 差集.
  set<int> A = {3, 2, 1, 4, 7, 9, 11};
  set<int> B = {6, 2, 9};
  vector<int> C;
  C.reserve(A.size());
  for (auto iter = A.begin(); iter != A.end(); ++iter)
    if (B.find(*iter) == B.end())
      C.push_back(*iter);
  for (const auto& x : C)
    cout << x << " ";
  cout << endl;

  // 转存.
  set<int> D = {3, 5, 1, 7, 2, 8, 0};
  set<int> E;
  while (!D.empty())
  {
    if (*D.begin() % 2 == 0)
      E.insert(*D.begin());
    D.erase(D.begin());
  }
  for (const auto& x : E)
    cout << x << " ";
  cout << endl;

  // 动态变化.
  set<string> F = {"English", "Ability", "Algorithm", "Faith"};
  while (F.size() > 1)
  {
    string first = *F.begin();
    F.erase(F.begin());
    string second = *F.begin();
    F.erase(F.begin());
    F.insert(first + second);
  }
  if (F.size() > 0)
    cout << *F.begin() << endl;

  return 0;
}
