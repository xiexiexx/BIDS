#include <iostream>
#include <vector>
#include <utility>
#include <map>

using std::vector;
using std::pair;
using std::map;
using std::cout;
using std::endl;

template <typename T>
struct bnode {
  T data;
  bnode<T>* left;
  bnode<T>* right;
};

template <typename T>
bnode<T>* binary_tree_construction(vector<pair<size_t, T>>& D,
                                   vector<bnode<T>>& R)
{
  if (D.size() == 0)
    return NULL;
  R.resize(D.size());
  map<size_t, size_t> M;
  size_t i = 0;
  for (const auto& x : D)
  {
    if (M.find(x.first) != M.end())
      return NULL;
    R[i].data = x.second;
    M[x.first] = i++;
  }
  auto iter = M.begin();
  if (iter->first != 1)
    return NULL;
  for (++iter; iter != M.end(); ++iter)
  {
    size_t c = iter->first;
    size_t p = c / 2;
    if (M.find(p) == M.end())
      return NULL;
    if (2 * p == c)
      R[M[p]].left = &R[c];
    else
      R[M[p]].right = &R[c];
  }
  return &R[0];
}

template <typename T>
bnode<T>* scan_binary_tree_construction(vector<pair<size_t, T>>& D,
                                        vector<bnode<T>>& R)
{
  if (D.size() == 0)
    return NULL;
  sort(D.begin(), D.end());
  auto iter = unique(D.begin(), D.end());
  if (iter != D.end())
    return NULL;
  if (D[0].first != 1)
    return NULL;
  R.resize(D.size());
  R[0].data = D[0].second;
  size_t p = 0;
  size_t c = 1;
  while (c < D.size())
  {
    // 让p移动到合适的位置.
    while (D[p].first < D[c].first / 2)
      ++p;
    // 如果p不符合要求则返回空指针.
    if (D[p].first != D[c].first / 2)
      return NULL;
    // 这种方案可推广到m叉树, 可用循环一次考虑完所有孩子.
    if (2 * D[p].first == D[c].first)
      R[p].left = &R[c++];
    if (2 * D[p].first + 1 == D[c].first)
      R[p].right = &R[c++];
    R[c].data = D[c].second;
  }
  return &R[0];
}

int main()
{
  vector<bnode<int>> R;
  vector<pair<size_t, int>> A {{3, 8}, {1, 9}, {6, 7}};
  vector<pair<size_t, int>> B {{3, 2}, {5, 1}, {1, 6}};
  vector<pair<size_t, int>> C {{2, 2}, {5, 0}, {10, 3}};
  cout << binary_tree_construction(A, R) << endl;
  cout << binary_tree_construction(B, R) << endl;
  cout << binary_tree_construction(C, R) << endl;
  cout << scan_binary_tree_construction(A, R) << endl;
  cout << scan_binary_tree_construction(B, R) << endl;
  cout << scan_binary_tree_construction(C, R) << endl;
  return 0;
}
