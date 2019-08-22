#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int main()
{
  size_t L = 9;   // 字符串长度.
  size_t B = 10;  // 基数.
  // 如果是特别长的字符串, 可以考虑用list<string>型链表存储原始数据.
  // 不要用字符串向量再配上字符串指针向量来变动操作, 那样效果不好.
  vector<string> phone_numbers(10000000, "123456789");
  // 如果处理很长的字符串, 可将队列换为链表, 也即vector<list<string>>型,
  // 所对应的入队出队操作换为链表的splice操作, 这样更快.
  vector<queue<string>> Q(B);
  // d从L - 1到0, 注意用法.
  size_t d = L;
  while (d > 0)
  {
    --d;
    // 根据第d位的数字处理字符串.
    for (const auto& x : phone_numbers)
      Q[x[d] - '0'].push(x);
    size_t i = 0;
    for (size_t k = 0; k < B; ++k)
      while (!Q[k].empty())
      {
        phone_numbers[i++] = Q[k].front();
        Q[k].pop();
      }
  }
  return 0;
}
