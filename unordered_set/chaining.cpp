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
  vector<set<int>> SH(n);
  vector<vector<int>> VH(n);
  vector<list<int>> LH(n);
  hash<int> h;
  for (const auto& x : K)
  {
    size_t pos = h(x) % n;
    SH[pos].insert(x);
    if (find(VH[pos].begin(), VH[pos].end(), x) == VH[pos].end())
      VH[pos].push_back(x);
    if (find(LH[pos].begin(), LH[pos].end(), x) == LH[pos].end())
      LH[pos].push_front(x);
  }
  print_all(SH);
  print_all(VH);
  print_all(LH);
  for (const auto& x : K)
  {
    size_t pos = h(x) % n;
    SH[pos].erase(x);
    auto iter = find(VH[pos].begin(), VH[pos].end(), x);
    if (iter != VH[pos].end())
      VH[pos].erase(iter);
    LH[pos].remove(x);
  }
  return 0;
}
