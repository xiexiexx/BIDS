#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct pnode {
  int key;
  bool empty;
  bool gone;
};

inline size_t probe(int k, size_t i, size_t m)
{
  return (((size_t) k) + i ) % m;
}

void insert(int k, vector<pnode>& H)
{
  for (size_t i = 0; i < H.size(); ++i)
  {
    size_t pos = probe(k, i, H.size());
    if (H[pos].empty)
    {
      H[pos].empty = false;
      H[pos].key = k;
      break;
    }
    else if (H[pos].gone)
    {
      H[pos].gone = false;
      H[pos].key = k;
      break;
    }
    else if (k == H[pos].key)
      break;
  }
}

size_t search(int k, const vector<pnode>& H)
{
  for (size_t i = 0; i < H.size(); ++i)
  {
    size_t pos = probe(k, i, H.size());
    if (H[pos].empty)
      return H.size();
    else if (!H[pos].gone && H[pos].key == k)
      return pos;
  }
  return H.size();
}

void rehashing(vector<pnode>& H)
{
  vector<pnode> W(2 * H.size());
  for (auto& x : W)
  {
    x.empty = true;
    x.gone = false;
  }
  for (const auto& x : H)
    if (!x.empty && !x.gone)
      insert(x.key, W);
  H.swap(W);
}

int main()
{
  vector<int> V = {-7, 4, 3, -6, 5, 4, 22, 71, 42, -96, 81, 12, 105};
  vector<pnode> H(2 * V.size());
  for (auto& x : H)
  {
    x.empty = true;
    x.gone = false;
  }
  for (const auto& x : V)
    insert(x, H);
  size_t pos = search(42, H);
  if (pos != H.size())
    H[pos].gone = true;
  insert(42, H);
  rehashing(H);
  for (const auto& x : H)
    if (!x.empty && !x.gone)
      cout << x.key << endl;
  return 0;
}
