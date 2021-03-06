#include <iostream>
#include <chrono>

using namespace std;

// 约占15GB内存.
const int n = 65536;
int M[n][n];

// 方法1: 一趟赋值.
void once()
{
  int x = 4;
  int y = 2;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      M[i][j] = (i == j) ? x : y;
}

// 方法2: 两趟赋值.
void twice()
{
  int x = 4;
  int y = 2;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      M[i][j] = y;
  for (int k = 0; k < n; ++k)
    M[k][k] = x;
}

// 方法3: 依然一趟赋值.
void only_once()
{
  int x = 4;
  int y = 2;
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < i; ++j)
      M[i][j] = y;
    M[i][i] = x;
    for (int j = i + 1; j < n; ++j)
      M[i][j] = y;
  }
}

// 打印耗时情况.
inline void print_duration(std::chrono::steady_clock::time_point start_t,
                           std::chrono::steady_clock::time_point end_t)
{
  std::cout << (std::chrono::duration<double>(end_t - start_t).count() / 60)
            << " minutes" << std::endl;
}

int main()
{
  auto start_t = std::chrono::steady_clock::now();
  once();
  auto end_t = std::chrono::steady_clock::now();
  print_duration(start_t, end_t);
  start_t = std::chrono::steady_clock::now();
  twice();
  end_t = std::chrono::steady_clock::now();
  print_duration(start_t, end_t);
  start_t = std::chrono::steady_clock::now();
  only_once();
  end_t = std::chrono::steady_clock::now();
  print_duration(start_t, end_t);
  return 0;
}
