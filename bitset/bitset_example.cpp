#include <iostream>
#include <bitset>
using namespace std;

template <size_t N>
inline void CL(bitset<N>& S, size_t W)
{
  W %= N;
  S = S << W | S >> (N - W);
}

template <size_t N>
inline void CR(bitset<N>& S, size_t W)
{
  W %= N;
  S = S >> W | S << (N - W);
}

int main()
{
  const size_t N = 16;
  bitset<N> A;
  cout << A.size() << endl;
  size_t pos = 7;
  A.set(pos);
  cout << A.count() << endl;
  A.set(pos, false);
  cout << A.count() << endl;
  cout << (A[pos] == true) << endl;
  A.flip(pos);
  cout << A.count() << endl;
  A.flip();
  cout << A.count() << endl;
  cout << A << endl;
  for (size_t i = 0; i < A.size(); ++i)
    cout << A[i];
  cout << endl;
  A >>= 1;
  cout << A << endl;
  size_t number = 5;
  bitset<N> B(number);
  cout << B << endl;
  size_t W = 4;
  auto C = B << W;
  cout << B << endl;
  cout << C << endl;
  B >>= W;
  cout << B << endl;
  C >>= W;
  cout << C << endl;
  CL(C, W);
  cout << C << endl;
  CR(C, W);
  cout << C << endl;
  return 0;
}
