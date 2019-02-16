#include <iostream>
#include <ctime>
#include <unordered_set>

using namespace std;

inline double time(clock_t start, clock_t end)
{
  return static_cast<double>(end - start) / static_cast<double>(CLOCKS_PER_SEC);
}

int main()
{
  const size_t n = 1000000000;
  unordered_set<size_t> S;
  // 整个运行过程最大约占用43GB.
  clock_t start = clock();
  for (size_t i = 0; i < n; ++i)
    S.insert(i);
  clock_t end = clock();
  cout << "运行时间(s): " << time(start, end) << endl;
  S.clear();
  // 由于数据量比较大, 普通的max_load_factor设定值对最终的空间占用影响不大.
  S.max_load_factor(0.5);
  S.reserve(n);
  start = clock();
  for (size_t i = 0; i < n; ++i)
    S.insert(i);
  end = clock();
  cout << "运行时间(s): " << time(start, end) << endl;
  return 0;
}
