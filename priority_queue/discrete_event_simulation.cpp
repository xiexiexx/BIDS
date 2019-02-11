#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <random>

using namespace std;

struct event {
  string name;
  size_t time;
  size_t station;
};

int main()
{
  auto cmp = [](event a, event b) { return a.time > b.time; };
  priority_queue<event, vector<event>, decltype(cmp)> PQ(cmp);
  PQ.push({"B1", 60, 0});
  PQ.push({"B2", 80, 0});
  PQ.push({"B3", 100, 0});
  vector<size_t> gap = {5, 9, 8, 6, 7, 6, 4, 7};
  default_random_engine generator;
  uniform_int_distribution<size_t> distribution(0, 5);
  while (!PQ.empty())
  {
    event E = PQ.top();
    PQ.pop();
    cout << "Current time: " << E.time
         << ", Bus: " << E.name
         << ", Station: " << E.station << endl;
    if (E.station != gap.size())
    {
      size_t delay = distribution(generator);
      E.time += gap[E.station++] + delay;
      PQ.push(E);
    }
  }
  return 0;
}
