#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
struct tnode {
  T data;
  tnode<T>* left;
  tnode<T>* right;
  tnode<T>* parent;
};

template <typename iterator>
void pre_order(iterator p)
{
  if (p != NULL)
  {
    cout << p->data << ' ';
    pre_order(p->left);
    pre_order(p->right);
  }
}

template <typename iterator>
void in_order(iterator p)
{
  if (p != NULL)
  {
    in_order(p->left);
    cout << p->data << ' ';
    in_order(p->right);
  }
}

template <typename iterator>
void post_order(iterator p)
{
  if (p != NULL)
  {
    post_order(p->left);
    post_order(p->right);
    cout << p->data << ' ';
  }
}

template <typename iterator>
void level_order(iterator p)
{
  queue<iterator> Q;
  if (p != NULL)
    Q.push(p);
  while (!Q.empty())
  {
    iterator f = Q.front();
    cout << f->data << ' ';
    if (f->left != NULL)
      Q.push(f->left);
    if (f->right != NULL)
      Q.push(f->right);
    Q.pop();
  }
}

double alpha;

template <typename iterator>
iterator tree_generation(iterator start, size_t n)
{
  if (n < 1)
    return NULL;
  size_t pivot = (n - 1) * alpha;
  size_t L = pivot;
  size_t R = n - 1 - pivot;
  iterator current = start + pivot;
  iterator left_root = tree_generation(start, L);
  iterator right_root = tree_generation(start + pivot + 1, R);
  current->left = left_root;
  current->right = right_root;
  if (left_root != NULL)
    left_root->parent = current;
  if (right_root != NULL)
    right_root->parent = current;
  return current;
}

template <typename iterator>
iterator left_most(iterator p)
{
  while (p->left != NULL)
    p = p->left;
  return p;
}

template <typename iterator>
iterator right_most(iterator p)
{
  while (p->right != NULL)
    p = p->right;
  return p;
}

template <typename iterator>
iterator next_position(iterator p)
{
  if (p->right != NULL)
    return left_most(p->right);
  iterator last = p;
  while (p != NULL)
  {
    if (last == p->left)
      return p;
    last = p;
    p = p->parent;
  }
  return p;
}

template <typename iterator>
iterator prev_position(iterator p)
{
  if (p->left != NULL)
    return right_most(p->left);
  iterator last = p;
  while (p != NULL)
  {
    if (last == p->right)
      return p;
    last = p;
    p = p->parent;
  }
  return p;
}

int main()
{
  size_t n;
  cin >> n;
  if (n < 1)
    return 0;

  vector<tnode<size_t>> tree(n);
  for (size_t i = 0; i < tree.size(); ++i)
    tree[i].data = i;
  alpha = 0.3;
  auto root = tree_generation(&tree[0], tree.size());
  root->parent = NULL;

  pre_order(root);
  cout << endl;
  in_order(root);
  cout << endl;
  post_order(root);
  cout << endl;
  level_order(root);
  cout << endl;

  for (auto p = left_most(root); p != NULL; p = next_position(p))
    cout << p->data << ' ';
  cout << endl;
  for (auto p = right_most(root); p != NULL; p = prev_position(p))
    cout << p->data << ' ';
  cout << endl;

  return 0;
}
