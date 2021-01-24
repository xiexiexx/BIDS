#include <vector>
#include <iostream>
#include <queue>

using namespace std;

template <typename T>
void merge(const vector<vector<T>>& V, vector<T>& S)
{
  // 统计有序序列的元素总数n.
  size_t n = 0;
  for (const auto& X : V)
    n += X.size();
  S.clear();
  S.reserve(n);
  // 以范围形式描述当前待处理的有序序列.
  using range = pair<decltype(V[0].begin()), decltype(V[0].end())>;
  auto cmp = [](range a, range b) { return *(b.first) < *(a.first); };
  priority_queue<range, vector<range>, decltype(cmp)> PQ(cmp);
  for (const auto& X : V)
    if (X.begin() != X.end())
      PQ.push({X.begin(), X.end()});
  while (!PQ.empty())
  {
    auto interval = PQ.top();
    PQ.pop();
    S.push_back(*(interval.first++));
    if (interval.first != interval.second)
      PQ.push(interval);
  }
}

int main()
{
  vector<vector<int>> A {{1, 2, 4}, {}, {2, 3, 5}, {3, 4, 6, 8}};
  // A[0], A[1], A[2], A[3]均为有序向量.
  vector<int> B;
  merge(A, B);
  for (const auto& x : B)
    cout << x << endl;
  return 0;
}
