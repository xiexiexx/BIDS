#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct tnode {
  size_t data;
  tnode* left;
  tnode* right;
  tnode* parent;
};

void pre_order(tnode* p)
{
  if (p != NULL)
  {
    cout << p->data << ' ';
    pre_order(p->left);
    pre_order(p->right);
  }
}

void in_order(tnode* p)
{
  if (p != NULL)
  {
    in_order(p->left);
    cout << p->data << ' ';
    in_order(p->right);
  }
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

void level_order(tnode* p)
{
  queue<tnode*> Q;
  if (p != NULL)
    Q.push(p);
  while (!Q.empty())
  {
    tnode* f = Q.front();
    cout << f->data << ' ';
    if (f->left != NULL)
      Q.push(f->left);
    if (f->right != NULL)
      Q.push(f->right);
    Q.pop();
  }
}

const double alpha = 0.3;

tnode* tree_generation(tnode* start, size_t n)
{
  if (n < 1)
    return NULL;
  size_t pivot = (n - 1) * alpha;
  size_t L = pivot;
  size_t R = n - 1 - pivot;
  tnode* current = start + pivot;
  tnode* left_root = tree_generation(start, L);
  tnode* right_root = tree_generation(start + pivot + 1, R);
  current->left = left_root;
  current->right = right_root;
  if (left_root != NULL)
    left_root->parent = current;
  if (right_root != NULL)
    right_root->parent = current;
  return current;
}

void left_most(tnode*& p)
{
  while (p->left != NULL)
    p = p->left;
}

void right_most(tnode*& p)
{
  while (p->right != NULL)
    p = p->right;
}

void next(tnode*& p)
{
  if (p->right != NULL)
  {
    p = p->right;
    left_most(p);
  }
  else
    while (p != NULL)
    {
      tnode* prev = p;
      p = p->parent;
      if (p != NULL & prev == p->left)
        break;
    }
}

void prev(tnode*& p)
{
  if (p->left != NULL)
  {
    p = p->left;
    right_most(p);
  }
  else
    while (p != NULL)
    {
      tnode* next = p;
      p = p->parent;
      if (p != NULL & next == p->right)
        break;
    }
}

int main()
{
  size_t n;
  cin >> n;
  if (n < 1)
    return 0;

  vector<tnode> tree(n);
  for (size_t i = 0; i < tree.size(); ++i)
    tree[i].data = i;
  tnode* root = tree_generation(&tree[0], tree.size());

  pre_order(root);
  cout << endl;
  in_order(root);
  cout << endl;
  post_order(root);
  cout << endl;
  level_order(root);
  cout << endl;

  tnode* min = root;
  left_most(min);
  tnode* max = root;
  right_most(max);
  for (tnode* p = min; p != NULL; next(p))
    cout << p->data << ' ';
  cout << endl;
  for (tnode* p = max; p != NULL; prev(p))
    cout << p->data << ' ';
  cout << endl;

  return 0;
}
