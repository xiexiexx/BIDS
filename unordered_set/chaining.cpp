#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <string>

using namespace std;

template <typename T>
void print_all(const T& H)
{
  for (const auto& B : H)
  {
    cout << "> ";
    for (const auto& x : B)
      cout << x << ' ';
    cout << endl;
  }
  cout << string(80, '=') << endl;
}

int main()
{
  vector<int> K {89, -738, 2118, -439, 43289, 89, 67, 251};
  size_t u = 2 * K.size();
  vector<set<int>> S(u);
  vector<vector<int>> V(u);
  vector<list<int>> L(u);
  hash<int> h;
  for (const auto& x : K)
  {
    size_t pos = h(x) % u;
    S[pos].insert(x);
    if (find(V[pos].begin(), V[pos].end(), x) == V[pos].end())
      V[pos].push_back(x);
    if (find(L[pos].begin(), L[pos].end(), x) == L[pos].end())
      L[pos].push_front(x);
  }
  print_all(S);
  print_all(V);
  print_all(L);
  for (const auto& x : K)
  for (size_t i = 0; i < 2; ++i)
  {
    size_t pos = h(x) % u;
    S[pos].erase(x);
    auto iter = find(V[pos].begin(), V[pos].end(), x);
    if (iter != V[pos].end())
    {
      *iter = move(V[pos].back());
      V[pos].pop_back();
    }
    L[pos].remove(x);
  }
  return 0;
}
