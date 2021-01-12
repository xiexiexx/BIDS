#include <iostream>
#include <vector>

using namespace std;

int main()
{
  // 定义一个初始长度为10的向量A, 可用位置数为10.
  vector<int> A(10);
  // 下标i从0到A.size() - 1对A中每个元素赋值i.
  // 为简便起见i使用size_t型, 若用vector<int>::size_type型更严谨.
  // 向量下标用法与数组相同, 但要注意不必自行统计元素个数,
  // 应保证向量中实有元素个数恒为size(), 即便短暂失效也要快速复位.
  for (size_t i = 0; i < A.size(); ++i)
    A[i] = static_cast<int>(i);
  // 使用迭代器iter对向量A中每个元素赋值1.
  // 迭代器可从向量的开始到结束, 类似指针.
  // 要注意begin()和end()的用法:
  // begin()位置是首元素, 而end()位置没有元素存在.
  // iter为vector<int>::iterator型,
  // 可用auto关键字配合赋值语句自动获取其类型.
  for (auto iter = A.begin(); iter != A.end(); ++iter)
    *iter = 1;

  // 定义一个长度为5的向量B, 初始元素全为3.
  vector<int> B(5, 3);
  // 在向量B末尾加入100个2.
  B.resize(B.size() + 100, 2);
  // 在向量B的尾部加入4.
  B.push_back(4);
  // 迭代器的另一种用法
  auto iter = B.begin();
  for (size_t i = 0; i < B.size(); ++i)
    *(iter + i) *= 2;
  // 若向量B不为空, 则持续打印其尾部元素并删除之.
  while(!B.empty())
  {
    cout << B.back() << endl; // 打印向量B的末尾元素
    B.pop_back();             // 删除向量B的末尾元素
  }

  // 接收未知长度的自然数输入序列, 以负数作为输入终止. C初始为空向量.
  vector<int> C;
  int data;
  // 基于push_back操作的速度非常快.
  for (cin >> data; data >= 0; cin >> data)
    C.push_back(data);
  for (const auto& x : C)
    cout << x << endl;

  // 向量的初始化列表.
  vector<int> D = {4, 2, 1, 5, 3};

  return 0;
}
