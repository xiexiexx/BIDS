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
  vector<int> A = {1, 2, 3};
  vector<int> B = {2, 4};
  vector<int> C(A.size() + B.size());
  auto IA = A.begin();
  auto IB = B.begin();
  size_t i = 0;
  while (IA != A.end() && IB != B.end())
      C[i++] = *IA < *IB ? *IA++ : *IB++;
  while (IA != A.end())
    C[i++] = *IA++;
  while (IB != B.end())
    C[i++] = *IB++;
  print_all(C);
  merge(A.begin(), A.end(), B.begin(), B.end(), C.begin());
  print_all(C);
  auto IC = C.begin();
  for (IA = A.begin(); IA != A.end(); ++IA)
    *IC++ = *IA;
  auto IM = IC;
  for (IB = B.begin(); IB != B.end(); ++IB)
    *IC++ = *IB;
  inplace_merge(C.begin(), IM, C.end());
  print_all(C);
  list<string> D = {"Kruskal", "Prim"};
  list<string> E = {"Dijkstra", "Floyd", "Warshall"};
  auto ID = D.begin();
  auto IE = E.begin();
  while (ID != D.end() && IE != E.end())
    if (*ID < *IE)
      ++ID;
    else
      D.insert(ID, *IE++);
  D.insert(ID, IE, E.end());
  print_all(D);
  return 0;
}
