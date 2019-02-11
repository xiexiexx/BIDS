#include <iostream>
#include <bitset>
#include <vector>
#include <ctime>

using namespace std;

int main()
{
  const size_t N = 60000000;
  vector<bool> A(N, true);
  bitset<N> B;
  B.flip();
  double start_t, end_t;  // 计时器.
  const size_t L = 100;
  start_t = clock();
  for (size_t i = 0; i < L; ++i)
    for (size_t j = 0; j < A.size(); ++j)
      if (j % 2 == 1)
        A[j] = false;
  end_t = clock();
  std::cout << (end_t - start_t) / (CLOCKS_PER_SEC * 60)
            << " minutes" << std::endl;
  start_t = clock();
  for (size_t i = 0; i < L; ++i)
    for (size_t j = 0; j < B.size(); ++j)
      if (j % 2 == 1)
        B[j] = false;
  end_t = clock();
  std::cout << (end_t - start_t) / (CLOCKS_PER_SEC * 60)
            << " minutes" << std::endl;
  return 0;
}
