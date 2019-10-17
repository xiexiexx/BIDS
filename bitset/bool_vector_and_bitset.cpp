#include <iostream>
#include <bitset>
#include <vector>
#include <ctime>

using namespace std;

int main()
{
  const size_t n = 60000000;
  vector<bool> A(n, true);
  bitset<n> B;
  B.flip();
  double start_t, end_t;
  const size_t loop = 100;
  start_t = clock();
  for (size_t i = 0; i < loop; ++i)
    for (size_t j = 0; j < A.size(); ++j)
      if (j % 2 == 1)
        A[j] = false;
  end_t = clock();
  std::cout << (end_t - start_t) / (CLOCKS_PER_SEC * 60)
            << " minutes" << std::endl;
  start_t = clock();
  for (size_t i = 0; i < loop; ++i)
    for (size_t j = 0; j < B.size(); ++j)
      if (j % 2 == 1)
        B[j] = false;
  end_t = clock();
  std::cout << (end_t - start_t) / (CLOCKS_PER_SEC * 60)
            << " minutes" << std::endl;
  return 0;
}
