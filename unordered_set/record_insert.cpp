#include <iostream>
#include <string>
#include <ctime>
#include <unordered_set>

using namespace std;

struct record {
  string name;
  int age;
  size_t code;
  string location;
};

inline double time(clock_t start, clock_t end)
{
  return static_cast<double>(end - start) / static_cast<double>(CLOCKS_PER_SEC);
}

// 整个运行过程最大约占用10GB, 可根据硬件配置将n改小以保证运行.
const size_t n = 100000000;
const double f = 0.5;

int main()
{
  auto hf = [] (const record& x) { return hash<size_t>()(x.code); };
  auto eql = [] (const record& a, const record& b) { return a.code == b.code; };
  unordered_set<record, decltype(hf), decltype(eql)> S(0, hf, eql);
  S.max_load_factor(f);
  S.reserve(n);
  clock_t start = clock();
  for (size_t i = 0; i < n; ++i)
    S.insert({"X", 20, i, "SH"});
  clock_t end = clock();
  cout << "运行时间(s): " << time(start, end) << endl;
  return 0;
}
