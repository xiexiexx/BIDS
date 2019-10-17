#include <iostream>
#include <bitset>
using namespace std;

template <size_t n>
inline void CL(bitset<n>& S, size_t w)
{
  w %= n;
  S = S << w | S >> (n - w);
}

template <size_t n>
inline void CR(bitset<n>& S, size_t w)
{
  w %= n;
  S = S >> w | S << (n - w);
}

int main()
{
  const size_t n = 16;
  bitset<n> A;
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
  bitset<n> B(number);
  cout << B << endl;
  size_t w = 4;
  auto C = B << w;
  cout << B << endl;
  cout << C << endl;
  B >>= w;
  cout << B << endl;
  C >>= w;
  cout << C << endl;
  CL(C, w);
  cout << C << endl;
  CR(C, w);
  cout << C << endl;
  return 0;
}
