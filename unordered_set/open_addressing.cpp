#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

template <typename T>
struct pnode {
  T key;
  bool empty;
  bool gone;
};

template <typename T>
inline size_t probe(T k, size_t i, size_t m)
{
  hash<T> h;
  return (h(k) + i) % m;
}

template <typename T>
void fill_blanks(vector<pnode<T>>& H)
{
  for (auto& x : H)
  {
    x.empty = true;
    x.gone = false;
  }
}

// 插入元素之前得先查找保证该元素不在集合中.
template <typename T>
void insert(vector<pnode<T>>& H, T k)
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
  }
}

template <typename T>
size_t search(const vector<pnode<T>>& H, T k)
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

template <typename T>
void print_all(const vector<pnode<T>>& H)
{
  for (const auto& x : H)
    if (!x.empty && !x.gone)
      cout << x.key << endl;
  cout << string(80, '=') << endl;
}

template <typename T>
void rehashing(vector<pnode<T>>& H)
{
  vector<pnode<T>> W(2 * H.size());
  fill_blanks(W);
  for (const auto& x : H)
    if (!x.empty && !x.gone)
      insert(W, x.key);
  H.swap(W);
}

int main()
{
  vector<int> V {-7, 4, 3, -6, 5, 4, 22, 71, 42, -96, 81, 12, 105};
  vector<pnode<int>> H(2 * V.size());
  fill_blanks(H);
  for (const auto& x : V)
    insert(H, x);
  size_t pos = search(H, 42);
  if (pos != H.size())
    H[pos].gone = true;
  print_all(H);
  insert(H, 42);
  rehashing(H);
  insert(H, 7);
  print_all(H);
  return 0;
}
