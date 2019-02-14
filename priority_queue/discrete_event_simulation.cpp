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
  const size_t N = 30;  // 车辆总数.
  const size_t D = 20;  // 发车间隔.
  for (size_t i = 0; i < N; ++i)
    PQ.push({"B" + to_string(i + 1), i * D, 0});
  // 相邻站点之间的最短到达时间.
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
