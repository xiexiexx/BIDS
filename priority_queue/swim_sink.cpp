#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::less;

// 打印堆中元素.
template <typename T>
void print_heap(const vector<T>& H)
{
  // 不考虑哨兵位置H[0].
  for (size_t i = 1; i < H.size(); ++i)
    cout << H[i] << ' ';
  cout << endl;
}

// 上浮操作, 默认使用less<T>(), 也可自行定义.
template <typename T, typename compare = less<T>>
void swim(vector<T>& H, size_t i, compare cmp = compare())
{
  // 在H[0]处设置哨兵以终止循环, 并保存结点i的初始数据(记为x).
  // 如果H[0]大于结点i的父亲结点数据值H[i / 2]则不断让i的位置上浮,
  // 但是初始数据x暂不处理, 仍存于H[0].
  for (H[0] = H[i]; cmp(H[i / 2], H[0]); i /= 2)
    H[i] = H[i / 2];
  // 将初始数据x存于上浮操作最终停留的位置.
  H[i] = H[0];
}

// 下沉操作, 默认使用less<T>(), 也可自行定义.
template <typename T, typename compare = less<T>>
void sink(vector<T>& H, size_t i, compare cmp = compare())
{
  // 暂存结点i的初始数据(记为x), 注意后续操作是和H[0]比较.
  H[0] = H[i];
  // 结点的右孩子编号.
  size_t right = 2 * i + 1;
  // 右孩子存在(即左右孩子均存在)时的下沉.
  while (right < H.size())
  {
    // position为较大结点的编号, 注意其初值为0.
    size_t position = 0;
    // 右孩子较大则position换为右孩子编号.
    if (cmp(H[position], H[right]))
      position = right;
    // 左孩子较大则position换为左孩子编号.
    if (cmp(H[position], H[right - 1]))
      position = right - 1;
    // 断言: 不需要交换则下沉结束.
    if (position == 0)
      break;
    // 需要交换时先将较小的孩子存于i位置, 再继续向下判断.
    H[i] = H[position];
    i = position;
    right = 2 * i + 1;
  }
  // 处理特殊情况: 最后仅存在左孩子且需要继续下沉.
  if (right == H.size() && cmp(H[0], H[right - 1]))
  {
    // 需要交换时先将左孩子存于i位置, 获得最终停留位置.
    H[i] = H[right - 1];
    i = right - 1;
  }
  // 将初始数据x存于下沉操作最终停留的位置.
  H[i] = H[0];
}

int main()
{
  // 给出最大堆H, 注意堆顶元素是H[1], H[0]用作哨兵.
  vector<int> H {{}, 9, 8, 7, 5, 6, 4, 3, 1, 0, 2};
  // 改变堆中若干元素的值并调整, 特别注意堆顶和堆尾.
  // 元素值增加则进行上浮操作, 元素值减少则进行下沉操作.
  int d = 10;
  H[5] += d;
  swim(H, 5);
  print_heap(H);
  H.back() += d;
  swim(H, H.size() - 1);
  print_heap(H);
  H[2] -= d;
  sink(H, 2);
  print_heap(H);
  H[1] -= d;
  sink(H, 1);
  print_heap(H);
  // 如果是最小堆, 上浮和下沉要补上参数std::greater<int>().
  return 0;
}
