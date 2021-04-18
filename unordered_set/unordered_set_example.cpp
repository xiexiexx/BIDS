#include <iostream>
#include <vector>
#include <unordered_set>

using std::cout;
using std::endl;
using std::vector;
using std::unordered_set;

// 注意到本例中两次打印迭代器区间中的所有元素, 不妨实现print_all函数.
// 如果换成print_all调用可让代码更简洁, 具体修改作为练习.
template <typename IR>
void print_all(IR left, IR right)
{
  while (left != right)
    cout << *left++ << ' ';
  cout << endl;
}

// 逐个打印S中每个桶内所存放的数据.
template <typename T>
void print_buckets(const unordered_set<T>& S)
{
  for (size_t i = 0; i < S.bucket_count(); ++i)
  {
    cout << "Bucket " << i << ": ";
    // 桶i的迭代器区间为[begin(i), end(i)).
    for (auto iter = S.begin(i); iter != S.end(i); ++iter)
      cout << *iter << ' ';
    cout << endl;
  }
}

int main()
{
  vector<int> V {7, 4, 3, -6, 5, 4, 22, 71, 42, -96, 81, 12, 105};
  unordered_set<int> S(V.begin(), V.end());
  S.insert(23);
  S.erase(5);
  print_buckets(S);
  // 以迭代器遍历并打印S中所有元素, 从逻辑上可以认为S是无序的.
  for (auto iter = S.begin(); iter != S.end(); ++iter)
    cout << *iter << ' ';
  cout << endl;
  auto iter = S.begin();
  while (iter != S.end())
    if (*iter % 2 == 0)
      iter = S.erase(iter);
    else
      ++iter;
  for (const auto& x : S)
    cout << x << ' ';
  cout << endl;
  print_buckets(S);
  // 打印S的最大装填因子和装填因子.
  cout << "Max Load Factor: " << S.max_load_factor() << endl;
  cout << "Load Factor: " << S.load_factor() << endl;
  // 将S的最大装填因子设为0.5, 注意该操作可能会引发重散列.
  S.max_load_factor(0.5);
  for (const auto& x : V)
    S.insert(-x);
  print_buckets(S);
  cout << "Max Load Factor: " << S.max_load_factor() << endl;
  cout << "Load Factor: " << S.load_factor() << endl;
  return 0;
}
