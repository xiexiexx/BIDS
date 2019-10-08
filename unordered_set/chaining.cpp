#include <iostream>
#include <vector>
#include <set>
#include <list>

using namespace std;

template <typename T>
void print_all(const T& H)
{
  for (const auto& B : H)
  {
    for (const auto& x : B)
      cout << x << ' ';
    cout << endl;
  }
  cout << "==================" << endl;
}

int main()
{
  vector<int> K = {89, -738, 2118, -439, 43289, 89, 67, 251};
  size_t n = 2 * K.size();
  vector<set<int>> S(n);
  vector<vector<int>> V(n);
  vector<list<int>> L(n);
  hash<int> h;
  for (const auto& x : K)
  {
    size_t pos = h(x) % n;
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
  {
    size_t pos = h(x) % n;
    S[pos].erase(x);
    auto iter = find(V[pos].begin(), V[pos].end(), x);
    if (iter != V[pos].end())
      V[pos].erase(iter);
    L[pos].remove(x);
  }
  return 0;
}
