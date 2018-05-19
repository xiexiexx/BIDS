#include <iostream>
#include <vector>

using namespace std;

size_t iterative_Collatz(size_t n)
{
  if (n < 1)
    return 0;
  size_t L = 1;
  while (n != 1)
  {
    n = (n % 2 == 0) ? n / 2 : 3 * n + 1;
    ++L;
  }
  return L;
}

size_t memoized_Collatz(vector<size_t>& v, size_t n)
{
  if (n < 1)
    return 0;
  // 如果n不在向量v的下标范围之内, 先转换到合理范围之内并计算偏移L.
  size_t L = 0;
  while (n >= v.size())
  {
    n = (n % 2 == 0) ? n / 2 : 3 * n + 1;
    ++L;
  }
  // 对v[n]进行赋值, 注意此处n在向量v的下标范围之内, 直接递归加1赋值即可.
  if (v[n] == 0)
    v[n] = memoized_Collatz(v, (n % 2 == 0) ? n / 2 : 3 * n + 1) + 1;
  // 返回值是原有的n对应的序列长度, 应加上偏移量L.
  return v[n] + L;
}

int main()
{
  // 利用备忘录保存已算出的值, 适合多次求解.
  const size_t m = 10000;
  vector<size_t> v(m, 0);
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
