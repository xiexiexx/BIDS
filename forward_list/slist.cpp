#include <iostream>
#include <vector>

using namespace std;

struct snode {
  int data;
  snode* next;
};

int main()
{
  snode sentinal;
  snode* header = &sentinal;
  snode A = {1, NULL};
  snode B = {2, NULL};
  snode C = {3, NULL};
  snode* p;
  p = header;
  p->next = &A;
  p = p->next;
  p->next = &B;
  p = p->next;
  p->next = &C;
  for (p = header->next; p != NULL; p = p->next)
    cout << p->data << endl;

  // 先将结点A之后的结点B删除.
  p = &A;
  snode* q = p->next;
  p->next = q->next;
  // 再将刚删除的结点B插入到结点C之后.
  p = p->next;
  q->next = p->next;
  p->next = q;
  for (p = header->next; p != NULL; p = p->next)
    cout << p->data << endl;

  vector<snode> V = {{}, {1, NULL}, {2, NULL}, {3, NULL}};
  header = p = &V[0];
  for (size_t i = 1; i < V.size(); ++i)
  {
    p->next = &V[i];
    p = p->next;
  }
  for (p = header->next; p != NULL; p = p->next)
    cout << p->data << endl;

  return 0;
}
