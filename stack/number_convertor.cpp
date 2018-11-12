#include <iostream>
#include <stack>
#include <string>
using namespace std;

void convertor_with_stack(int number, size_t b)
{
  string d2c = "0123456789ABCDEF";
  string result;  // 实际上是栈, 但这里用字符串更方便.
  if (number < 0)
  {
    result += "-";
    number = -number;
  }
  stack<char> S;
  do {
    S.push(d2c[number % b]);
    number /= b;
  } while (number != 0);
  while (!S.empty())
  {
    result += S.top();
    S.pop();
  }
  cout << result << endl;
}

void convertor_with_string(int number, size_t b)
{
  string d2c = "0123456789ABCDEF";
  string result;      // 实际上是栈, 但这里用字符串更方便.
  size_t start = 0;   // 结果字符串中逆置的起点.
  if (number < 0)
  {
    result += "-";
    number = -number;
    start = 1;
  }
  do {
    result.push_back(d2c[number % b]);
    number /= b;
  } while (number != 0);
  // 由于使用了字符串, 我们直接逆置[start, result.size())位置,
  // 当然也可前面先单独保留'-'字符等逆置结束后再拼接.
  for (size_t i = start; i < (result.size() + start) / 2; ++i)
    swap(result[i], result[result.size() - 1 - i + start]);
  cout << result << endl;
}

int main()
{
  cout << "请输入需要转换的数:";
  int number;
  cin >> number;
  size_t b;
  cout << "请输入所转换的进制(2-16之间):";
  cin >> b;
  if (b >= 2 && b <= 16)
  {
    convertor_with_stack(number, b);
    convertor_with_string(number, b);
  }
  else
    cout << "进制输入有误!" << endl;
  return 0;
}
