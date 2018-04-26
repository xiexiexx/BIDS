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
  // 前提条件是n > 0.
  size_t L = 1;
  while (n >= v.size())
  {
    n = (n % 2 == 0) ? n / 2 : 3 * n + 1;
    ++L;
  }
  if (v[n] == 0)
    v[n] = memoized_Collatz(v, (n % 2 == 0) ? n / 2 : 3 * n + 1) + L;
  return v[n];
}

int main()
{
  size_t n;
  cin >> n;
  // 利用迭代直接求解.
  cout << iterative_Collatz(n) << endl;
  // 利用备忘录保存已算出的值, 适合多次求解.
  const size_t m = 10000;
  vector<size_t> v(m, 0);
  v[1] = 1;
  if (n < 1)
    cout << 0 << endl;
  else
    cout << memoized_Collatz(v, n) << endl;
  return 0;
}
