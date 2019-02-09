#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
void print_all(const T& S)
{
  for (const auto& x : S)
    cout << x << ' ';
  cout << endl;
}

int main()
{
  // 将向量视为堆.
  vector<int> V = {2, 3, 1, 5, 4};
  make_heap(V.begin(), V.end());
  // 直接处理堆中元素.
  auto A = V;
  print_all(A);
  pop_heap(A.begin(), A.end());
  A.pop_back();
  cout << A.front() << endl;
  A.push_back(9);
  push_heap(A.begin(), A.end());
  cout << A.front() << endl;
  // 利用pop_heap完成堆排序, 最大堆最后变成从小到大按升序排练的向量.
  auto B = V;
  for (size_t d = B.size(); d > 1; d--)
  {
    pop_heap(B.begin(), B.begin() + d);
    print_all(B);
  }
  // 利用sort_heap排序, 最大堆最后变成从小到大按升序排练的向量.
  auto C = V;
  sort_heap(C.begin(), C.end());
  print_all(C);
  return 0;
}
