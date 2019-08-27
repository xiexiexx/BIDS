#include <iostream>
#include <string>
#include <stack>
using namespace std;

// 4种状态常量以及对应提示语, 注意使用text时下标要加上偏移d.
const int d = 4;
enum status {not_matched = -4, matched = -3, illegal = -2, in = -1};
string text[d] = {"不匹配", "匹配", "存在非法字符", ""};

int generalized_validator(const string& brackets, int value[])
{
  stack<char> S;
  for (size_t i = 0; i < brackets.size(); ++i)
    if (value[(int)brackets[i]] == illegal)                   // 非法符号直接退出.
      return illegal;
    else if (value[(int)brackets[i]] == in)                   // 左括号应该进栈.
      S.push(brackets[i]);
    else if (S.empty() || S.top() != value[(int)brackets[i]]) // 无法弹栈.
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
  value[(int)'('] = in;
  value[(int)')'] = '(';
  value[(int)'{'] = in;
  value[(int)'}'] = '{';
  value[(int)'['] = in;
  value[(int)']'] = '[';
  string brackets;
  cin >> brackets;
  cout << text[d + generalized_validator(brackets, value)] << endl;
  return 0;
}
