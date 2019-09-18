#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct PR {
  size_t parent;
  size_t rank;
};

void U(vector<PR>& DS, size_t x, size_t y)
{
  if (x == y)
    return;
  if (DS[x].rank < DS[y].rank)
    DS[x].parent = y;
  else if (DS[y].rank < DS[x].rank)
    DS[y].parent = x;
  else
  {
    DS[y].parent = x;
    ++DS[x].rank;
  }
}

// 使用栈完成, 如果将栈换成外部的向量并提前预留容量, 速度会快很多.
size_t F_with_stack(vector<PR>& DS, size_t x)
{
  stack<size_t> S;
  while (DS[x].parent != x)
  {
    S.push(x);
    x = DS[x].parent;
  }
  while (!S.empty())
  {
    DS[S.top()].parent = x;
    S.pop();
  }
  return x;
}

// 使用两次迭代完成.
size_t F(vector<PR>& DS, size_t x)
{
  size_t root = x;
  while (DS[root].parent != root)
    root = DS[root].parent;
  while (x != root)
  {
    size_t parent = DS[x].parent;
    DS[x].parent = root;
    x = parent;
  }
  return root;
}

void print(const vector<PR>& DS)
{
  cout << "parent: ";
  for (auto const& e : DS)
    cout << e.parent << ", ";
  cout << endl << "  rank: ";
  for (auto const& e : DS)
    cout << e.rank << ", ";
  cout << endl << endl;
}

int main()
{
  vector<PR> DS(7);
  for (size_t i = 0; i < DS.size(); ++i)
    DS[i] = {i, 0};
  U(DS, F(DS, 1), F(DS, 5));
  print(DS);
  U(DS, F(DS, 1), F(DS, 6));
  print(DS);
  U(DS, F(DS, 2), F(DS, 4));
  print(DS);
  U(DS, F(DS, 5), F(DS, 4));
  print(DS);
  return 0;
}
