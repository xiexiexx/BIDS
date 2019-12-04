#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
  // 最大优先级队列.
  priority_queue<int> M;
  M.push(2);
  M.push(3);
  M.push(1);
  cout << M.top() << endl;
  M.pop();
  cout << M.top() << endl;
  // 最小优先级队列, 关键是将判断准则改为greater<int>, 亦可自行定义准则.
  priority_queue<int, vector<int>, greater<int>> W;
  W.push(2);
  W.push(3);
  W.push(1);
  while (!W.empty())
  {
    cout << W.top() << endl;
    W.pop();
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
