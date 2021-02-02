#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
  vector<int> V {2, 0, 2, 1};

  // 方案1: 使用下标.
  // 此处size_t尽量不要用int代替.
  for (size_t i = 0; i < V.size(); i++)
    cout << V[i] << ' ';

  // 方案2: 使用vector<int>::const_iterator型常量迭代器citer,
  // 注意常量迭代器只读不写, 相当于加了const约束.
  // 这里特别以cbegin和cend区别于begin和end,
  // 从而保证citer是常量迭代器.
  for (auto citer = V.cbegin(); citer != V.cend(); ++citer)
    cout << *citer << ' ';

  // 方案3: 基于范围的for循环, 由于不会改动向量, 所以可加const约束.
  for (const auto& x: V)
    cout << x << ' ';
  // 由于存储的是int元素, 也可以用复制的方式for(auto x : V),
  // 将V中元素逐个复制到x中再打印, 不适合体积较大的元素.

  // 方案4: 使用copy算法.
  // 必须包含algorithm和iterator头文件.
  // 另外空格要用字符串形式" "而不能用字符形式' '.
  copy (V.cbegin(), V.cend(), ostream_iterator<int>(cout, " "));

  return 0;
}
