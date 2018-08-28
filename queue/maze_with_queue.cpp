#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 为方便讲解, 我们不定义point的相等(==)和不相等(!=)运算符.
struct point {
  int x;
  int y;
};

int main()
{
  const int M = 5;
  const int N = 7;
  char unvisited = '0'; // 未访问过的标记.
  char visited = 'V';   // 访问过的标记.
  // 迷宫字符数组, 周围一圈全是墙(以'*'标记).
  char maze[M][N] = {
      {'*', '*', '*', '*', '*', '*', '*'},
      {'*', '0', '*', '0', '0', '0', '*'},
      {'*', '0', '*', '0', '*', '0', '*'},
      {'*', '0', '0', '0', '*', '0', '*'},
      {'*', '*', '*', '*', '*', '*', '*'}
  };
  const int d = 4;      // 可行方向总数.
  // 以下标取值0, 1, 2, 3标记东南西北与当前位置的偏移量.
  point delta [d] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  // 起点与终点的坐标.
  point source = {1, 1};
  point destination = {3, 5};
  point parent[M][N];                       // 用于保存父亲所在位置.
  queue<point> Q;                           // 搜索时所用队列.
  vector<point> P;                          // 保存最终路径.
  Q.push(destination);                      // 初始点设为出口点.
  size_t length = 0;
  bool solved = false;
  while (!Q.empty())
  {
    // length每次增量为increment, 如果有新点入队则increment为1.
    size_t increment = 0;
    for (size_t i = 0; i < d; ++i)
    {
      point neighbor = {Q.front().x + delta[i].x, Q.front().y + delta[i].y};
      if (maze[neighbor.x][neighbor.y] == unvisited)
      {
        increment = 1;
        maze[neighbor.x][neighbor.y] = visited;
        parent[neighbor.x][neighbor.y] = Q.front();
        Q.push(neighbor);
        if (neighbor.x == source.x && neighbor.y == source.y)
        {
          solved = true;
          break;  // 注意这个break只跳出了当前for循环.
        }
      }
    }
    length += increment;
    if (solved)
    {
      P.reserve(length + 1);      // 提前预留空间.
      P.push_back(source);
      while (P.back().x != destination.x || P.back().y != destination.y)
        P.push_back(parent[P.back().x][P.back().y]);
      break;      // 这个break才真正跳出了while循环.
    }
    Q.pop();
  }
  for (size_t i = 0; i < P.size(); ++i)
    cout << P[i].x << ' ' << P[i].y << endl;
  return 0;
}

