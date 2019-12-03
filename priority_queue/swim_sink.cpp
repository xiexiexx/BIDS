#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void print_heap(const vector<T>& H)
{
  // 不考虑哨兵位置H[0].
  for (size_t i = 1; i < H.size(); ++i)
    cout << H[i] << ' ';
  cout << endl;
}

template <typename T>
void swim(vector<T>& H, size_t i)
{
  // 在H[0]处设置哨兵以终止循环, 并保存初始结点i处的数据.
  // 如果H[0]大于i位置的父亲结点值H[i / 2]则不断让i位置上浮,
  // 但初始结点处的数据暂不处理, 其值仍存于H[0].
  for (H[0] = H[i]; H[i / 2] < H[0]; i /= 2)
    H[i] = H[i / 2];
  // 将初始结点处的数据存于上浮操作最终停留的位置.
  H[i] = H[0];
}

template <typename T>
void sink(vector<T>& H, size_t i)
{
  // 暂存H[i]数据, 注意后续操作是和H[0]比较.
  H[0] = H[i];
  // 结点的右孩子编号.
  size_t right = 2 * i + 1;
  // 右孩子存在(即左右孩子均存在)时的下沉.
  while (right < H.size())
  {
    // position为较大结点的编号, 注意其初值为0.
    size_t position = 0;
    // 右孩子较大则position换为右孩子编号.
    if (H[position] < H[right])
      position = right;
    // 左孩子较大则position换为左孩子编号.
    if (H[position] < H[right - 1])
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
  if (right == H.size() && H[0] < H[right - 1])
  {
    // 需要交换时先将左孩子存于i位置, 获得最终停留位置.
    H[i] = H[right - 1];
    i = right - 1;
  }
  // 将初始结点处的数据存于下沉操作最终停留的位置.
  H[i] = H[0];
}

int main()
{
  int sentinal;
  vector<int> H = {sentinal, 9, 8, 7, 5, 6, 4, 3, 1, 0, 2};
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
  return 0;
}
