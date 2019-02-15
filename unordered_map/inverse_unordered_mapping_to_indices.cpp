#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
  vector<pair<string, string>> G = {
    {"O(1)", "O(logn)"}, {"O(n)", "O(n^2)"}, {"O(logn)", "O(n)"}
  };
  // 利用unordered_map处理逆映射.
  vector<string> M;
  M.reserve(2 * G.size());
  unordered_map<string, size_t> IM;
  IM.max_load_factor(0.5);
  IM.reserve(M.capacity());
  for (const auto& x : G)
  {
    if (IM.count(x.first) == 0)
    {
      M.push_back(x.first);
      IM[x.first] = M.size() - 1;
    }
    if (IM.count(x.second) == 0)
    {
      M.push_back(x.first);
      IM[x.second] = M.size() - 1;
    }
    cout << IM.bucket_count() << " Bucket(s), Load Factor: "
         << IM.load_factor() << endl;
  }
  for (const auto& x : G)
    cout << IM[x.first] << ", " << IM[x.second] << endl;
  return 0;
}
