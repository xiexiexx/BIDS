#include <iostream>
#include <queue>
#include <vector>
#include <string>

using std::queue;
using std::vector;
using std::string;
using std::cout;
using std::endl;

// 为方便讲解, 我们不定义point的相等(==)和不相等(!=)运算符.
struct point {
  size_t x;
  size_t y;
  bool operator==(const point&) const = default;
};

struct status {
  point pt;
  size_t level;
};

int main()
{
  const char unvisited = '0'; // 未访问过的标记.
  const char visited = 'V';   // 访问过的标记.
  // 迷宫字符数组, 周围一圈全是墙(以'*'标记).
  vector<string> maze {
    "*******",
    "*0*000*",
    "*0*0*0*",
    "*000*0*",
    "*******"
  };
  const size_t m = maze.size();
  const size_t n = maze[0].size();
  const size_t d = 4;      // 可行方向总数.
  // 以下标取值0, 1, 2, 3标记东南西北与当前位置的偏移量.
  const point delta[d] = {{0, 1}, {1, 0}, {0, (size_t) -1}, {(size_t) -1, 0}};
  // 起点与终点的坐标.
  point source = {1, 1};
  point destination = {m - 2, n - 2};
  point parent[m][n];                       // 用于保存父亲所在位置.
  queue<status> Q;                          // 搜索时所用队列.
  vector<point> P;                          // 保存最终路径.
  Q.push({destination, 0});                 // 初始点设为出口点并指定初始层次.
  maze[destination.x][destination.y] = visited;
  while (!Q.empty())
  {
    for (int direction = 0; direction < d; ++direction)
    {
      point neighbor = {Q.front().pt.x + delta[direction].x,
                        Q.front().pt.y + delta[direction].y};
      if (maze[neighbor.x][neighbor.y] == unvisited)
      {
        parent[neighbor.x][neighbor.y] = Q.front().pt;
        if (neighbor == source)
        {
          // 提前预留空间, 当然也可以不用保存到P中, 直接基于parent数组打印.
          P.reserve(Q.front().level + 2);
          P.push_back(source);
          while (P.back() != destination)
            P.push_back(parent[P.back().x][P.back().y]);
          for (const auto& c : P)
            cout << c.x << ' ' << c.y << endl;
          // 如果使用break语句只能跳出当前for循环, 还要设置标记变量跳出外层while循环,
          // 不如直接返回结束整个程序.
          return 0;
        }
        maze[neighbor.x][neighbor.y] = visited;
        Q.push({neighbor, Q.front().level + 1});
      }
    }
    Q.pop();
  }
  return 0;
}
