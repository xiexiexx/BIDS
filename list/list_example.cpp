#include <iostream>
#include <forward_list>
#include <list>

using namespace std;

int main()
{
  forward_list<int> A = {1, 2, 3};
  auto ia = A.begin();
  cout << *ia << endl;
  ++ia;
  cout << *ia << endl;
  list<int> B = {1, 2, 3};
  auto ib = B.begin();
  cout << *ib << endl;
  ++ib;
  cout << *ib << endl;
  --ib;
  cout << *ib << endl;
  auto rib = B.rbegin();
  cout << *rib << endl;
  ++rib;
  cout << *rib << endl;
  --rib;
  cout << *rib << endl;
  list <int> C = {1, 2, 3};
  *C.begin() = 0;
  cout << *C.begin() << endl;
  *C.rbegin() = 4;
  cout << *C.rbegin() << endl;
  return 0;
}
