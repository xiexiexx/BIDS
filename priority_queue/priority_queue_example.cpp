#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
  // 最大优先级队列.
  priority_queue<int> MAXPQ;
  MAXPQ.push(2);
  MAXPQ.push(3);
  MAXPQ.push(1);
  cout << MAXPQ.top() << endl;
  MAXPQ.pop();
  cout << MAXPQ.top() << endl;
  // 最小优先级队列, 关键是将判断准则改为greater<int>, 亦可自行定义准则.
  priority_queue<int, vector<int>, greater<int>> MINPQ;
  MINPQ.push(2);
  MINPQ.push(3);
  MINPQ.push(1);
  while (!MINPQ.empty())
  {
    cout << MINPQ.top() << endl;
    MINPQ.pop();
  }
  // 使用向量初始化最大堆的数据.
  vector<int> V = {2, 3, 1};
  priority_queue<int> PQ(V.begin(), V.end());
  while (PQ.size() > 0)
  {
    cout << PQ.top() << endl;
    PQ.pop();
  }
  return 0;
}
