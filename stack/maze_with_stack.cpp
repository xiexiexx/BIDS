#include <iostream>
#include <vector>
using namespace std;

struct status {
  int x;
  int y;
  int direction;
};

const int d = 4;      // 可行方向总数.

void find_next(status& current, status& next)
{
  // 以direction取值0, 1, 2, 3标记东南西北.
  pair<int, int> delta [d] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  next.x = current.x + delta[current.direction].first;
  next.y = current.y + delta[current.direction].second;
}

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
  // 起点与终点的状态.
  status source = {1, 1, 0};
  status destination = {3, 5, 0};
  vector<status> path;                      // 搜索时保留路径所用的向量.
  path.reserve(M * N);                      // 提前预留容量.
  path.push_back(source);                   // 初始点设为入口点.
  while (!path.empty())
    if (path.back().direction < d)
    {
      status next;
      find_next(path.back(), next);
      ++path.back().direction;
      if (maze[next.x][next.y] == unvisited)
      {
        maze[next.x][next.y] = visited;
        next.direction = 0;   // 设置next的初始方向.
        path.push_back(next);
        // 放到路径向量后再判断该点是否为终点并及时跳出循环.
        if (next.x == destination.x && next.y == destination.y)
          break;
      }
    }
    else
      path.pop_back();
  for (size_t i = 0; i < path.size(); ++i)
    cout << path[i].x << ' ' << path[i].y << endl;
  return 0;
}

