#include <iostream>
#include <vector>

using namespace std;

struct xnode{
  vector<xnode*> links;
  bool membership;
  static const size_t n = 256;
};

int main()
{
  vector<string> V {"Apple", "X-Men", "42", "Algorithm", "Algorithms"};
  size_t L = 0;
  for (const auto& s : V)
    L += s.size();
  vector<xnode> trie;
  trie.reserve(L + 1);
  trie.push_back({vector<xnode*>()});
  xnode* root = &trie[0];
  // 根据V中的字符串建立trie的结构.
  for (const auto& s : V)
  {
    xnode* p = root;
    for (const auto& c : s)
    {
      size_t index = (size_t) c;
      if (p->links.empty())
        p->links.resize(xnode::n, NULL);
      if (p->links[index] == NULL)
      {
        trie.push_back({vector<xnode*>(), false});
        p->links[index] = &trie.back();
      }
      p = p->links[index];
    }
    p->membership = true;
  }
  // 在trie中查找W中所有字符串, 在屏幕上输出找到的字符串.
  vector<string> W {"Algorithm", "Pencil", "42"};
  for (const auto& s : W)
  {
    xnode* p = root;
    for (const auto& c : s)
    {
      size_t index = (size_t) c;
      if (p->links.empty() || p->links[index] == NULL)
        break;
      p = p->links[index];
    }
    // 注意: 按照上述逻辑运行后, p不会是NULL.
    if (p->membership)
      cout << s << endl;
  }
  return 0;
}
