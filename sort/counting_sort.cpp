#include <iostream>
#include <vector>

using namespace std;

int main()
{
  // 取值范围为[0, K)的排序.
  const int K = 42;
  vector<size_t> V = {18, 2, 6, 15, 6, 32, 1, 25, 0, 27, 15};
  // 对每个元素进行计数并给出它们最终排序后对范围.
  vector<size_t> C(K + 1, 0);
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
