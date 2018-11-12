#include <iostream>
#include <ctime>
#include <forward_list>

using namespace std;

inline double time(clock_t start, clock_t end)
{
  return static_cast<double>(end - start) / static_cast<double>(CLOCKS_PER_SEC);
}

int main()
{
  const size_t n = 100000000;
  forward_list<int> FL;
  clock_t start = clock();
  for (size_t i = 0; i < n; ++i)
    FL.push_front(0);
  clock_t end = clock();
  cout << "运行时间(s): " << time(start, end) << endl;
  return 0;
}
