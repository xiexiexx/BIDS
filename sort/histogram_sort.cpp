#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  vector<double> V = {0.8, 0.3, 0.6, 0.5, 0.4, 0.2, 0.1, 0.9, 0.0, 0.7};
  // 每个桶中期望元素个数, 理论值取1, 但一般会稍微取大一点.
  size_t E = 1;
  vector<size_t> C(V.size() / E + 1, 0);     // 使用计数方法.
  vector<double> B(V.size());                // 另一种形式的桶.
  // 对每个桶的元素进行计数.
  for (const auto& x : V)
    ++C[x * (V.size() / E) + 1];
  // 指示每个桶的起始位置.
  for (size_t i = 1; i < C.size(); ++i)
    C[i] += C[i - 1];
  // 将V中元素分配到不同的桶中.
  for (const auto& x : V)
    B[C[x * (V.size() / E)]++] = x;
  // 对不同的桶进行排序, 区间为[left, right).
  auto left = B.begin();
  for (size_t i = 1; i < C.size(); ++i)
  {
    auto right = B.begin() + C[i - 1];
    sort(left, right);
    left = right;
  }
  // 利用交换将数据放回原向量中.
  V.swap(B);
  for (const auto& x : V)
    cout << x << endl;
  return 0;
}
