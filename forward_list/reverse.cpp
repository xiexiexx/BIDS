#include <iostream>
#include <vector>
#include <forward_list>

using namespace std;

struct snode {
  int data;
  snode* next;
};

void traverse(snode* header)
{
  for (snode* p = header->next; p != NULL; p = p->next)
    cout << p->data << " ";
  cout << endl;
}

void reverse(snode* header)
{
  snode* prev = NULL;
  snode* curr = header->next;
  while (curr != NULL)
  {
    snode* next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  header->next = prev;
}

int main()
{
  vector<snode> V = {{}, {1, NULL}, {2, NULL}, {3, NULL}};
  for (size_t i = 0; i + 1 < V.size(); ++i)
    V[i].next = &V[i + 1];
  traverse(&V[0]);
  reverse(&V[0]);
  traverse(&V[0]);

  forward_list<int> FL = {1, 2, 3};
  FL.reverse();
  for (const auto& x : FL)
    cout << x << " ";
  cout << endl;
  return 0;
}
