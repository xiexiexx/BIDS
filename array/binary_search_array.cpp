#include <iostream>

using std::cout;
using std::endl;

// 输入: key - 待查值; data - 有序数组(从小到大排列); n - 数组长度.
// 输出: 所找到的位置.
template <typename T>
int binary_search_array(const T& key, const T data[], int n)
{
  if (n <= 0)
    return n;
  // 注意这种闭区间的写法让循环的判断条件有所不同.
  int low = 0;
  int high = n - 1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (key < data[mid])      // 小则去前半部分继续查找.
      high = mid - 1;
    else if (data[mid] < key) // 大则去后半部分继续查找.
      low = mid + 1;
    else
      return mid;
  }
  return n;
}

int main()
{
  int A[5] = {1, 2, 3, 4, 5};
  cout << binary_search_array(2, A, 5) << endl;
  cout << binary_search_array(0, A, 5) << endl;
  cout << binary_search_array(2, A, 0) << endl;
  // 注意查找的起始位置不同, 更像使用指针.
  cout << binary_search_array(2, A + 2, 3) << endl;
  return 0;
}
