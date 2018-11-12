#include <iostream>
#include <vector>
using namespace std;

struct tnode {
  int data;
  tnode* left;
  tnode* right;
};

pair<tnode*, bool> pre_in_build(int* pre, int* in, tnode* t, size_t n)
{
  if (n == 0)
    return {NULL, true};
  int* pivot = find(in, in + n, *pre);
  if (pivot == in + n)
    return {NULL, false};
  size_t L = pivot - in;
  size_t R = (in + n) - pivot - 1;
  auto left_result = pre_in_build(pre + 1, in, t + 1, L);
  auto right_result = pre_in_build(pre + 1 + L, in + 1 + L, t + 1 + L, R);
  if (!left_result.second || !right_result.second)
    return {NULL, false};
  *t = {*pivot, left_result.first, right_result.first};
  return {t, true};
}

void post_order(tnode* p)
{
  if (p != NULL)
  {
    post_order(p->left);
    post_order(p->right);
    cout << p->data << ' ';
  }
}

int main()
{
  vector<int> pre_order = {2, 0, 1, 4, 3, 5, 6, 8};
  vector<int> in_order = {0, 1, 2, 3, 4, 5, 6, 7};
  size_t n = pre_order.size();
  if (in_order.size() == n && n > 0)
  {
    vector<tnode> tree(n);
    auto result = pre_in_build(&pre_order[0], &in_order[0], &tree[0], n);
    if (result.second)
      post_order(result.first);
  }
  return 0;
}
