#include <iostream>
#include <ctime>
#include <vector>

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
  const size_t n = 1000000000;
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

  // 如果已知链的最终长度, 可以先用vector一次性申请内存以提速, 还可以避免手写代码释放内存.
  start = clock();
  vector<snode> L(n + 1);
  header = &L[0];
  for (size_t i = 0; i < n; ++i)
    L[i].next = &L[i + 1];
  L.back().next = NULL;
  end = clock();
  cout << "运行时间(s): " << time(start, end) << endl;

  return 0;
}
