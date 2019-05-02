#include <iostream>
#include <vector>

using namespace std;

uint64_t iterative_Collatz(size_t n)
{
  if (n < 1)
    return 0;
  uint64_t L = 1;
  while (n != 1)
  {
    n = (n % 2 == 0) ? n / 2 : 3 * n + 1;
    ++L;
  }
  return L;
}

// 调用本函数要求v的长度至少是2, 并且已初始化. 另外要求n >= 1.
uint64_t memoized_Collatz(vector<uint64_t>& v, size_t n)
{
  // 如果n不在向量v的下标范围之内, 先转换到合理范围之内并计算偏移D.
  uint64_t D = 0;
  while (n >= v.size()) // 注意此处如果v.size() <= 1则会出错.
  {
    n = (n % 2 == 0) ? n / 2 : 3 * n + 1;
    ++D;
  }
  // 对v[n]进行赋值, 注意此处n在向量v的下标范围之内, 直接递归加1赋值即可.
  if (v[n] == 0)
    v[n] = memoized_Collatz(v, (n % 2 == 0) ? n / 2 : 3 * n + 1) + 1;
  // 返回值是原有的n对应的序列长度, 应加上偏移量D.
  return v[n] + D;
}

int main()
{
  // 利用备忘录保存已算出的值, 适合多次求解.
  const size_t m = 10000;
  vector<uint64_t> v(m, 0);
  v[1] = 1;
  // 测试迭代和备忘录计算结果是否一致, 测试范围为[1, max].
  size_t max = 100000;
  bool equal = true;
  for (size_t n = 1; n <= max; ++n)
    if (iterative_Collatz(n) != memoized_Collatz(v, n))
      equal = false;
  cout << (equal ? "相符" : "不符") << endl;

  return 0;
}
