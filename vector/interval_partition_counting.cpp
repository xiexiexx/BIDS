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
  // 注意可将j的作用域扩大, 只用while(j < P[i + 1])即可.
  for (unsigned int i = 0; i < S.size(); ++i)
    for (int j = P[i]; j < P[i + 1]; ++j)
      S[i] += C[j - left];
  // 注意到P中的端点有序排列, 还可以换下面这种方案:
  // R也将记录每个子区间中元素出现的次数总和.
  vector<unsigned int> R(P.size() - 1, 0);
  unsigned int i = 0;
  for (int j = P.front(); j < P.back(); ++j)
  {
    // 若统计的值越过当前区间的右端点P[i + 1]则变换区间.
    // 注意我们使用<, 可推广到一般的有序端点情况.
    if (!(j < P[i + 1]))
      ++i;
    R[i] += C[j - left];
  }
  for (size_t i = 0; i < P.size() - 1; ++i)
    cout << "[" << P[i] << ", " << P[i + 1] << ") : "
         << S[i] << endl;
  for (size_t i = 0; i < P.size() - 1; ++i)
    cout << "[" << P[i] << ", " << P[i + 1] << ") : "
         << R[i] << endl;
}

int main()
{
  // 区间[P.front(), P.back())的划分P, 要求有序排列.
  vector<int> P {-3, 1, 6, 9, 11};
  // 数据向量D的数据均属于[P.front(), P.back())区间.
  vector<int> D {1, 3, 2, 2, 4, 5, 10, -3, 5};
  interval_partition_counting(P, D);
  return 0;
}
