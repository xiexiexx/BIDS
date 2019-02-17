#include <iostream>
#include <ctime>
#include <unordered_set>

using namespace std;

inline double time(clock_t start, clock_t end)
{
  return static_cast<double>(end - start) / static_cast<double>(CLOCKS_PER_SEC);
}

// 整个运行过程最大约占用43GB, 可根据硬件配置将n改小以保证运行.
const size_t n = 1000000000;
const double f = 0.5;

void insert(unordered_set<size_t>& S)
{
  for (size_t i = 0; i < n; ++i)
    S.insert(i);
}

size_t max(const unordered_set<size_t>& S)
{
  size_t M = 0;
  for (size_t i = 0; i < S.bucket_count(); ++i)
    if (S.bucket_size(i) > M)
      M = S.bucket_size(i);
  return M;
}

int main()
{
  unordered_set<size_t> S;
  // 直接放入, 约占用43GB空间.
  clock_t start = clock();
  insert(S);
  clock_t end = clock();
  cout << "运行时间(s): " << time(start, end) << endl;
  S.clear();
  // 提前预留容量, 约占用46GB空间.
  // 由于数据量比较大, 普通的max_load_factor设定值对最终的空间占用影响不大.
  S.max_load_factor(f);
  S.reserve(n);
  start = clock();
  insert(S);
  end = clock();
  cout << "运行时间(s): " << time(start, end) << endl;
  cout << "The maximal bucket of S has " << max(S) << " element(s)." << endl;
  S.clear();
  // 直接设定桶的数目, 约占用61GB空间.
  // 由于占用空间较大, 如果内存碎片较多, 会对性能产生一定影响, 得进行实测.
  unordered_set<size_t> W(n / f);
  W.max_load_factor(f);
  start = clock();
  insert(W);
  end = clock();
  cout << "运行时间(s): " << time(start, end) << endl;
  cout << "The maximal bucket of W has " << max(W) << " element(s)." << endl;
  return 0;
}
