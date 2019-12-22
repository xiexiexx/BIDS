#include <iostream>
#include <vector>

using namespace std;

int main()
{
  // 取值范围为[0, k)的排序, 对于一般情况可统计出最小值和最大值再平移转化成这种区间.
  const size_t k = 42;
  vector<size_t> V = {18, 2, 6, 15, 6, 32, 1, 25, 0, 27, 15};
  // 对每个元素进行计数并给出它们最终排序后的范围.
  vector<size_t> C(k + 1, 0);
  for (const auto& x : V)
    ++C[x + 1];
  for (size_t i = 1; i < C.size(); ++i)
    C[i] += C[i - 1];
  // 将所有元素放入最终结果S中.
  vector<size_t> S(V.size());
  for (const auto& x : V)
    S[C[x]++] = x;
  for (const auto& x : S)
    cout << x << endl;
  return 0;
}
