#include <iostream>
#include <forward_list>

using namespace std;

template <typename T>
struct snode {
  T data;
  snode* next;
};

template <typename IR>
bool cycle_detection(IR start)
{
  IR hare = start;
  IR tortoise = start;
  while (hare != NULL && hare->next != NULL && tortoise != NULL)
  {
    hare = hare->next->next;
    tortoise = tortoise->next;
    if (hare == tortoise)
      return true;
  }
  return false;
}

template <typename T>
void fast_and_slow(const forward_list<T>& FL)
{
  if (FL.empty())
    return;
  auto fast = FL.begin();
  auto slow = FL.begin();
  while(fast != FL.end() && ++fast != FL.end())
  {
      ++fast;
      ++slow;
  }
  cout << *slow << endl;
}

template <typename T>
void median(const forward_list<T>& FL)
{
  if (FL.empty())
    return;
  size_t n = 0;
  for (auto iter = FL.begin(); iter != FL.end(); ++iter)
    ++n;
  auto median = FL.begin();
  for (size_t i = 0; i < n / 2; ++i)
    ++median;
  cout << *median << endl;
}

int main()
{
  snode<int> cycle[3];
  cycle[0].next = &cycle[1];
  cycle[1].next = &cycle[2];
  cycle[2].next = &cycle[1];
  if (cycle_detection(&cycle[0]))
    cout << "Yes" << endl;
  size_t n = 50000000;
  forward_list<size_t> FL;
  auto iter = FL.before_begin();
  for (size_t i = 0; i < n; ++i)
    iter = FL.insert_after(iter, i);
  fast_and_slow(FL);
  median(FL);
  return 0;
}
