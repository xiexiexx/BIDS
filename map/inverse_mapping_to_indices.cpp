#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;

int main()
{
  vector<pair<string, string>> G 
    {{"O(1)", "O(logn)"}, {"O(n)", "O(n^2)"}, {"O(logn)", "O(n)"}};
  // 利用map处理逆映射.
  vector<string> M;
  M.reserve(2 * G.size());
  map<string, size_t> IM;
  for (const auto& x : G)
  {
    if (IM.find(x.first) == IM.end())
    {
      M.push_back(x.first);
      IM[x.first] = M.size() - 1;
    }
    if (IM.find(x.second) == IM.end())
    {
      M.push_back(x.second);
      IM[x.second] = M.size() - 1;
    }
  }
  for (const auto& x : G)
    cout << IM[x.first] << ", " << IM[x.second] << endl;
  return 0;
}
