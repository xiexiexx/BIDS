#include <iostream>
#include <vector>
using namespace std;

using graph = vector<vector<size_t>>;

int main()
{
  graph G {{1}, {2, 3}, {0}, {5}, {3}, {4}};
  vector<size_t> C(G.size(), 0);
  for (size_t u = 0; u < G.size(); ++u)
    for (const auto& v : G[u])
      ++C[v];
  graph GT(G.size());
  for (size_t i = 0; i < C.size(); ++i)
    GT[i].reserve(C[i]);
  for (size_t u = 0; u < G.size(); ++u)
    for (const auto& v : G[u])
      GT[v].push_back(u);
  // 将来还可以考虑In-place matrix transposition.
  for (size_t u = 0; u < GT.size(); ++u)
    for (const auto& v : GT[u])
      cout << "(" << u << ", " << v << ")" << endl;
  return 0;
}
