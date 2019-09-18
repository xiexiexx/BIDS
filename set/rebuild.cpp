#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
struct tnode {
  T data;
  tnode<T>* left;
  tnode<T>* right;
};

template <typename data_iterator, typename node_iterator>
bool pre_in_build(data_iterator pre, data_iterator in,
                  node_iterator root, size_t n)
{
  if (n == 0)
    return true;
  data_iterator pivot = find(in, in + n, *pre);
  if (pivot == in + n)
    return false;
  size_t cl = pivot - in;
  size_t cr = in + n - pivot - 1;
  if (!pre_in_build(pre + 1, in, root + 1, cl))
    return false;
  root->left = (cl == 0) ? NULL : root + 1;
  if (!pre_in_build(pre + 1 + cl, in + 1 + cl, root + 1 + cl, cr))
    return false;
  root->right = (cr == 0) ? NULL : root + 1 + cl;
  root->data = *pivot;
  return true;
}

template <typename node_iterator>
void post_order(node_iterator p)
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
  vector<string> pre_order = {"2", "0", "1", "4", "3", "5", "6", "7"};
  vector<string> in_order = {"0", "1", "2", "3", "4", "5", "6", "7"};
  size_t n = pre_order.size();
  if (n > 0 && in_order.size() == n)
  {
    vector<tnode<string>> tree(n);
    if (pre_in_build(&pre_order[0], &in_order[0], &tree[0], n))
      post_order(&tree[0]);
  }
  return 0;
}
