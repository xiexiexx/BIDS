#include <iostream>   // 输入输出流.
#include <ctime>      // 时间.
#include <algorithm>  // 算法库.
#include <vector>			// 向量.

using namespace std;  // 使用名字空间std.

inline double time(clock_t start, clock_t end)
{
  return static_cast<double>(end - start) / static_cast<double>(CLOCKS_PER_SEC);
}

int main()
{
  // 计时变量.
  clock_t start, end;
  const size_t N = 100000000;

  // 占用的存储量很大.
  vector<size_t> v(N);

  // 线性时间
  start = clock();
  for (size_t i = 0; i < v.size(); ++i)
    v[i] = v.size() - i;
  end = clock();
  cout << "运行时间(s): " << time(start, end) << endl;

  // 线对时间
  start = clock();
	sort(v.begin(), v.end());
  end = clock();
  cout << "运行时间(s): " << time(start, end) << endl;

	// 对数时间
  start = clock();
	binary_search(v.begin(), v.end(), 1);
  end = clock();
  cout << "运行时间(s): " << time(start, end) << endl;

  // 平方时间, 无法使用N这个规模量.
  size_t M = 100000;
  start = clock();
  for (size_t i = 0; i < M; ++i)
    for (size_t j = 0; j < M; ++j)
      v[i] *= j;
  end = clock();
  cout << "运行时间(s): " << time(start, end) << endl;
  // 如果是N这个规模量, 需要多少时间?
  cout << "估计运行时间(s): " << time(start, end) * (N / M) * (N / M) << endl;

  return 0;
}
