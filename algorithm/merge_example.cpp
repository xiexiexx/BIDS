#include <iostream>
#include <vector>
#include <list>
#include <string>
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
  vector<int> A {1, 2, 3};
  vector<int> B {2, 4};
  vector<int> C(A.size() + B.size());
  auto va = A.begin();
  auto vb = B.begin();
  size_t i = 0;
  while (va != A.end() && vb != B.end())
      C[i++] = *va < *vb ? *va++ : *vb++;
  while (va != A.end())
    C[i++] = *va++;
  while (vb != B.end())
    C[i++] = *vb++;
  print_all(C);
  merge(A.begin(), A.end(), B.begin(), B.end(), C.begin());
  print_all(C);
  auto vc = C.begin();
  for (va = A.begin(); va != A.end(); ++va)
    *vc++ = *va;
  auto vm = vc;
  for (vb = B.begin(); vb != B.end(); ++vb)
    *vc++ = *vb;
  inplace_merge(C.begin(), vm, C.end());
  print_all(C);
  list<string> D {"Kruskal", "Prim"};
  list<string> E {"Dijkstra", "Floyd", "Warshall"};
  auto ld = D.begin();
  auto le = E.begin();
  while (ld != D.end() && le != E.end())
    if (*ld < *le)
      ++ld;
    else
      D.insert(ld, *le++);
  D.insert(ld, le, E.end());
  print_all(D);
  return 0;
}
