#include <iostream>
#include <string>
#include <stack>
using namespace std;

// 各种状态常量:
const int matched = 1;
const int not_matched = 0;
const int illegal = -1;
const int start = -2;

int generalized_validator(const string& brackets, int status[])
{
  stack <char> S;
  for (size_t i = 0; i < brackets.size(); ++i)
    if (status[(int)brackets[i]] == illegal)      // 非法符号直接退出.
      return illegal;
    else if (status[(int)brackets[i]] == start)   // 左括号应该进栈.
      S.push(brackets[i]);
    else if (S.empty() || S.top() != status[(int)brackets[i]])  // 无法弹栈.
      return not_matched;
    else
      S.pop();
  return S.empty() ? matched : not_matched;
}

int main()
{
  const int N = 256;
  int status[N];
  for (size_t i = 0; i < N; ++i)
    status[i] = illegal;
  status[(int)'('] = start;
  status[(int)')'] = '(';
  status[(int)'{'] = start;
  status[(int)'}'] = '{';
  status[(int)'['] = start;
  status[(int)']'] = '[';
  string brackets;
  cin >> brackets;
  int result = generalized_validator(brackets, status);
  if (result == matched)
    cout << "匹配" << endl;
  else if (result == not_matched)
    cout << "不匹配" << endl;
  else
    cout << "存在非法字符" << endl;
  return 0;
}
