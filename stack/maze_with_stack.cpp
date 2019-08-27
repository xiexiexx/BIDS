#include <iostream>
#include <vector>
using namespace std;

// 为方便讲解, 我们不定义point的相等(==)和不相等(!=)运算符.
struct point {
  int x;
  int y;
};

struct status {
  point pt;
  int direction;  // 以direction取值0, 1, 2, 3标记东南西北.
};

const int d = 4;      // 可行方向总数.
// 以下标取值0, 1, 2, 3标记东南西北与当前位置的偏移量.
point delta[d] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void find_next(point& current, int direction, point& next)
{
  next.x = current.x + delta[direction].x;
  next.y = current.y + delta[direction].y;
}

int main()
{
  const int M = 5;
  const int N = 7;
  const char unvisited = '0'; // 未访问过的标记.
  const char visited = 'V';   // 访问过的标记.
  // 迷宫字符数组, 周围一圈全是墙(以'*'标记).
  char maze[M][N] = {
      {'*', '*', '*', '*', '*', '*', '*'},
      {'*', '0', '*', '0', '0', '0', '*'},
      {'*', '0', '*', '0', '*', '0', '*'},
      {'*', '0', '0', '0', '*', '0', '*'},
      {'*', '*', '*', '*', '*', '*', '*'}
  };
  // 起点与终点的状态.
  point source = {1, 1};
  point destination = {3, 5};
  vector<status> P;                         // 搜索时保留路径所用的向量, 可视为栈.
  P.reserve(M * N);                         // 提前预留容量.
  P.push_back({source, 0});                 // 初始点设为入口点, 并设定初始方向.
  while (!P.empty())
    if (P.back().direction < d)
    {
      point next;
      find_next(P.back().pt, P.back().direction, next);
      ++P.back().direction;
      if (maze[next.x][next.y] == unvisited)
      {
        maze[next.x][next.y] = visited;
        P.push_back({next, 0});
        // 放到路径向量后再判断该点是否为终点并及时跳出循环.
        if (next.x == destination.x && next.y == destination.y)
          break;
      }
    }
    else
      P.pop_back();
  for (size_t i = 0; i < P.size(); ++i)
    cout << P[i].pt.x << ' ' << P[i].pt.y << endl;
  return 0;
}
