#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

// 定义(二维平面)点结构体, 包含其x和y坐标值,
// 并以默认形式给出point的相等(==)运算符.
struct point {
  int x;
  int y;
  bool operator==(const point&) const = default;
};

// 状态包括点和方向, 不妨以direction取值0, 1, 2, 3标记东南西北.
struct status {
  point pt;
  int direction;
};

int main()
{
  const int m = 5;
  const int n = 7;
  // 未访问则标记为'0', 已访问则标记为'V'.
  const char unvisited = '0';
  const char visited = 'V';
  // 迷宫字符数组, 周围一圈全是墙(以'*'标记).
  char maze[m][n] = {
    {'*', '*', '*', '*', '*', '*', '*'},
    {'*', '0', '*', '0', '0', '0', '*'},
    {'*', '0', '*', '0', '*', '0', '*'},
    {'*', '0', '0', '0', '*', '0', '*'},
    {'*', '*', '*', '*', '*', '*', '*'}
  };
  // 可行方向总数为d.
  const int d = 4;
  // 以下标取值0, 1, 2, 3标记东南西北与当前位置的偏移量.
  const point delta[d] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  // 起点与终点的坐标.
  point source = {1, 1};
  point destination = {m - 2, n - 2};
  // 搜索时保留路径所用的向量P可视为栈.
  vector<status> P;
  // 提前预留容量, 以迷宫元素的总数为界.
  P.reserve(m * n);
  // 初始点设为入口点, 并设定初始方向.
  P.push_back({source, 0});
  if (source != destination)
  {
    maze[source.x][source.y] = visited;
    while (!P.empty())
      if (P.back().direction < d)
      {
        point next = {P.back().pt.x + delta[P.back().direction].x,
                      P.back().pt.y + delta[P.back().direction].y};
        // 调整下次将指示的方向.
        ++P.back().direction;
        if (maze[next.x][next.y] == unvisited)
        {
          maze[next.x][next.y] = visited;
          P.push_back({next, 0});
          // 放到路径向量后再判断该点是否为终点并及时跳出循环.
          // 这种方案得预先判定起点不得为终点, 否则会出错.
          if (next == destination)
            break;
        }
      }
      else
        P.pop_back();
  }
  for (const auto& c : P)
    cout << c.pt.x << ' ' << c.pt.y << endl;
  return 0;
}
