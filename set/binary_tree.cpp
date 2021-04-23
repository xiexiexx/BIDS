#include <iostream>
#include <vector>
#include <queue>

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::queue;

template <typename T>
struct bnode {
  T data;
  bnode<T>* left;
  bnode<T>* right;
  bnode<T>* parent;
};

// 处理结点数据. 这里使用打印功能, 也可换为其他操作.
template <typename IR>
void node_processing(IR p)
{
  cout << p->data << ' ';
}

// 前序遍历二叉树.
template <typename IR>
void pre_order(IR p)
{
  if (p != NULL)
  {
    node_processing(p);
    pre_order(p->left);
    pre_order(p->right);
  }
}

// 中序遍历二叉树.
template <typename IR>
void in_order(IR p)
{
  if (p != NULL)
  {
    in_order(p->left);
    node_processing(p);
    in_order(p->right);
  }
}

// 后序遍历二叉树.
template <typename IR>
void post_order(IR p)
{
  if (p != NULL)
  {
    post_order(p->left);
    post_order(p->right);
    node_processing(p);
  }
}

// 层次遍历二叉树.
template <typename IR>
void level_order(IR p)
{
  queue<IR> Q;
  if (p != NULL)
    Q.push(p);
  while (!Q.empty())
  {
    // 取出队首元素(结点指针).
    IR f = Q.front();
    Q.pop();
    node_processing(f);
    // 若有左孩子则将其入队.
    if (f->left != NULL)
      Q.push(f->left);
    // 若有右孩子则将其入队.
    if (f->right != NULL)
      Q.push(f->right);
  }
}

// 为方便起见, 将弯折率定义为全局变量.
double alpha;

// 从start位置开始向后取n个结点以弯折形式生成二叉树.
template <typename IR>
IR tree_generation(IR start, size_t n)
{
  if (n < 1)
    return NULL;
  // 计算根结点所在位置.
  size_t c = (n - 1) * alpha;
  IR root = start + c;
  // 分别生成左右子树的根结点指针.
  IR left_subtree = tree_generation(start, c);
  IR right_subtree = tree_generation(start + c + 1, n - 1 - c);
  // 设定相关指针值.
  root->left = left_subtree;
  root->right = right_subtree;
  if (left_subtree != NULL)
    left_subtree->parent = root;
  if (right_subtree != NULL)
    right_subtree->parent = root;
  return root;
}

// 若p指向非空二叉树的根结点, 寻找该树中的最左结点.
template <typename IR>
IR left_most(IR p)
{
  if (p == NULL)
    return NULL;
  while (p->left != NULL)
    p = p->left;
  return p;
}

// 若p指向非空二叉树的根结点, 寻找该树中的最右结点.
template <typename IR>
IR right_most(IR p)
{
  if (p == NULL)
    return NULL;
  while (p->right != NULL)
    p = p->right;
  return p;
}

// 若p指向非空二叉树中的某个结点x, 返回中序遍历意义下x的下一结点位置.
template <typename IR>
IR next_position(IR p)
{
  if (p->right != NULL)
    return left_most(p->right);
  // 以last保留p的原有位置并判断其关系.
  IR last;
  do
  {
    last = p;
    p = p->parent;
  } while (p != NULL && last != p->left);
  return p;
}

// 若p指向非空二叉树中的某个结点x, 返回中序遍历意义下x的上一结点位置.
template <typename IR>
IR prev_position(IR p)
{
  if (p->left != NULL)
    return right_most(p->left);
  // 以last保留p的原有位置并判断其关系.
  IR last;
  do
  {
    last = p;
    p = p->parent;
  } while (p != NULL && last != p->right);
  return p;
}

int main()
{
  size_t n;
  cin >> n;
  if (n < 1)
    return 0;
  // 将树的所有结点置于向量tree之中.
  vector<bnode<size_t>> tree(n);
  for (size_t i = 0; i < tree.size(); ++i)
    tree[i].data = i;
  alpha = 0.3;
  auto root = tree_generation(&tree[0], tree.size());
  root->parent = NULL;
  // 遍历二叉树.
  pre_order(root);
  cout << endl;
  in_order(root);
  cout << endl;
  post_order(root);
  cout << endl;
  level_order(root);
  cout << endl;
  // 按照中序遍历的次序, 以迭代形式访问整棵树.
  for (auto p = left_most(root); p != NULL; p = next_position(p))
    node_processing(p);
  cout << endl;
  for (auto p = right_most(root); p != NULL; p = prev_position(p))
    node_processing(p);
  cout << endl;
  return 0;
}
