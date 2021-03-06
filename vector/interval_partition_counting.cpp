#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void interval_partition_counting(const vector<int>& P,
                                 const vector<int>& D)
{
  if (P.size() < 2)
    return;
  vector<int> C(P.back() - P.front(), 0);
  int left = P.front();
  // 对数据D中各个元素x统计次数并存放于C[x - left]中.
  for (const auto& x : D)
    ++C[x - left];
  // S将记录每个子区间中元素出现的次数总和.
  vector<unsigned int> S(P.size() - 1, 0);
  for (unsigned int i = 0; i < S.size(); ++i)
    for (int j = P[i]; j < P[i + 1]; ++j)
      S[i] += C[j - left];
  for (size_t i = 0; i < P.size() - 1; ++i)
    cout << "[" << P[i] << ", " << P[i + 1] << ") : "
         << S[i] << endl;
}

int main()
{
  // 区间[P.front(), P.back())的划分P.
  vector<int> P {-3, 1, 6, 9, 11};
  // 数据向量D的数据均属于[P.front(), P.back())区间.
  vector<int> D {1, 3, 2, 2, 4, 5, 10, -3, 5};
  interval_partition_counting(P, D);
  return 0;
}
