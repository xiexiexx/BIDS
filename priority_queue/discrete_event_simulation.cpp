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
  const size_t n = 30;  // 车辆总数.
  const size_t d = 20;  // 发车间隔.
  for (size_t i = 0; i < n; ++i)
    PQ.push({"B" + to_string(i + 1), i * d, 0});
  // 相邻站点之间的最短到达时间.
  vector<size_t> M = {5, 9, 8, 6, 7, 6, 4, 7};
  default_random_engine generator;
  uniform_int_distribution<size_t> distribution(0, 5);
  while (!PQ.empty())
  {
    event current = PQ.top();
    PQ.pop();
    cout << "Current time: " << current.time
         << ", Bus: " << current.name
         << ", Station: " << current.station << endl;
    if (current.station != M.size())
    {
      size_t delay = distribution(generator);
      current.time += M[current.station++] + delay;
      PQ.push(current);
    }
  }
  return 0;
}
