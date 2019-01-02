#include <iostream>
#include <vector>
#include <set>
#include <list>

using namespace std;

template <typename T>
void print_all(const T& H)
{
  for (const auto& X : H)
  {
    for (const auto& Y : X)
      cout << Y << ' ';
    cout << endl;
  }
  cout << "==================" << endl;
}

int main()
{
  vector<int> K = {89, -738, 2118, -439, 43289, 89, 67, 251};
  size_t N = 2 * K.size();
  vector<set<int>> SH(N);
  vector<vector<int>> VH(N);
  vector<list<int>> LH(N);
  for (const auto& x : K)
  {
    size_t position = ((size_t) x) % N;
    SH[position].insert(x);
    if (find(VH[position].begin(), VH[position].end(), x) == VH[position].end())
      VH[position].push_back(x);
    if (find(LH[position].begin(), LH[position].end(), x) == LH[position].end())
      LH[position].push_front(x);
  }
  print_all(SH);
  print_all(VH);
  print_all(LH);
  for (const auto& x : K)
  {
    size_t position = ((size_t) x) % N;
    SH[position].erase(x);
    auto iter = find(VH[position].begin(), VH[position].end(), x);
    if (iter != VH[position].end())
      VH[position].erase(iter);
    LH[position].remove(x);
  }
}
