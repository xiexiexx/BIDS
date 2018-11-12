#include <iostream>
#include <ctime>

using namespace std;

inline double time(clock_t start, clock_t end)
{
  return static_cast<double>(end - start) / static_cast<double>(CLOCKS_PER_SEC);
}

struct snode {
  int data;
  snode* next;
};

int main()
{
  const size_t n = 100000000;
  clock_t start = clock();
  snode* header = new snode;
  snode* p = header;
  for (size_t i = 0; i < n; ++i)
  {
    snode* next = new snode;
    p->next = next;
    p = next;
  }
  p->next = NULL;
  clock_t end = clock();
  cout << "运行时间(s): " << time(start, end) << endl;
  p = header;
  while (p != NULL)
  {
    snode* next = p->next;
    delete p;
    p = next;
  }
  return 0;
}
