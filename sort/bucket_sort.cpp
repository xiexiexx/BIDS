#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  vector<double> V = {0.8, 0.3, 0.6, 0.5, 0.4, 0.2, 0.1, 0.9, 0.0, 0.7};
  // 每个桶中期望元素个数, 理论值取1, 但一般会稍微取大一点.
  size_t E = 1;
  vector<vector<double>> B(V.size() / E); // 桶.
  for (auto& b : B)
    b.reserve(E);
  // 将V中元素分配到不同的桶中.
  for (const auto& x : V)
    B[x * B.size()].push_back(x);
  for (auto& b : B)
    sort(b.begin(), b.end());
  size_t i = 0;
  for (const auto& b : B)
    for (const auto& x : b)
      V[i++] = x;
  for (const auto& x : V)
    cout << x << endl;
  return 0;
}
