#include <iostream>
#include <vector>

using namespace std;

int main()
{
  const size_t n = 40;
  // size()返回当前元素个数, capacity()返回当前容量.

  vector<int> A;
  for (size_t i = 0; i < n; ++i)
  {
    cout << A.size() << " " << A.capacity() << endl;
    A.push_back(0);
  }
  cout << A.size() << " " << A.capacity() << endl;

  vector<int> B;
  // 提前预留容量n.
  B.reserve(n);
  for (size_t i = 0; i < n; ++i)
  {
    cout << B.size() << " " << B.capacity() << endl;
    B.push_back(0);
  }
  cout << B.size() << " " << B.capacity() << endl;

  return 0;
}
