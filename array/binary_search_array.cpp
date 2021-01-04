#include <iostream>

using namespace std;

// 输入: key - 待查值; data - 有序数据集(从小到大排列); n - 数据集长度.
// 输出: 所找到的位置.
template <typename T>
int binary_search_array(const T& key, const T data[], int n)
{
  if (n <= 0)
    return n;
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
  int a[5] = {1, 2, 3, 4, 5};
  cout << binary_search_array(2, a, 5) << endl;
  cout << binary_search_array(0, a, 5) << endl;
  cout << binary_search_array(2, a + 2, 3) << endl;
  cout << binary_search_array(0, a, 0) << endl;
  return 0;
}
