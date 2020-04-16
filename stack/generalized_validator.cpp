#include <iostream>
#include <string>
#include <stack>
using namespace std;

// 4种状态常量以及对应提示语, 注意使用text时下标要加上偏移s.
const int s = 4;
enum status {not_matched = -4, matched = -3, illegal = -2, in = -1};
const string text[s] = {"不匹配", "匹配", "存在非法字符", ""};

int generalized_validator(const string& brackets, int value[])
{
  stack<char> S;
  for (auto x : brackets)
    if (value[(int)x] == illegal)                   // 非法符号直接退出.
      return illegal;
    else if (value[(int)x] == in)                   // 左括号应该进栈.
      S.push(x);
    else if (S.empty() || S.top() != value[(int)x]) // 无法弹栈.
      return not_matched;
    else
      S.pop();
  return S.empty() ? matched : not_matched;
}

int main()
{
  const int n = 256;
  int value[n];
  for (size_t i = 0; i < n; ++i)
    value[i] = illegal;
  value[(int)'L'] = in;
  value[(int)'R'] = (int)'L';
  value[(int)'<'] = in;
  value[(int)'>'] = (int)'<';
  value[(int)'['] = in;
  value[(int)']'] = (int)'[';
  string brackets;
  cin >> brackets;
  cout << text[s + generalized_validator(brackets, value)] << endl;
  return 0;
}
