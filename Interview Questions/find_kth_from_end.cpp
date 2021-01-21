#include <iostream>
#include <forward_list>
#include <ctime>

using namespace std;

// 计数.
template <typename IR>
IR count_and_find(IR left, IR right, size_t k)
{
  if (k < 1)
    return right;
  size_t n = 0;
  for (IR position = left; position != right; ++position)
    ++n;
  if (n < k)
    return right;
  for (size_t i = 0; i < n - k; ++i)
    ++left;
  return left;
}

// 双指针.
template <typename IR>
IR front_and_back(IR left, IR right, size_t k)
{
  if (k < 1)
    return right;
  IR front = left;
  for (size_t i = 0; i < k; ++i)
    if (front != right)
      ++front;
    else
      return right;
  IR back = left;
  while (front != right)
  {
    ++front;
    ++back;
  }
  return back;
}

// 基于平移的双指针.
template <typename IR>
IR updated_front_and_back(IR left, IR right, size_t k)
{
  if (k < 1)
    return right;
  IR front = left;
  size_t i;
  for (i = 0; i < k; ++i)
    if (front != right)
      ++front;
    else
      return right;
  IR back = left;
  i = 0;
  for (IR position = front; position != right; ++position, ++i)
    if (i == k)
    {
      i = 0;
      back = front;
      front = position;
    }
  while (front != right)
  {
    ++front;
    ++back;
  }
  return back;
}

// 重新利用计数和取模给出更多信息, 效果不好.
template <typename IR>
IR mod_updated_front_and_back(IR left, IR right, size_t k)
{
  if (k < 1)
    return right;
  size_t n = 0;
  IR front = left;
  IR back;
  for (IR position = left; position != right; ++position, ++n)
    if (n % k == 0)
    {
      back = front;
      front = position;
    }
  if (n < k)
    return right;
  if (n == k)
    return left;
  while (front != right)
  {
    ++front;
    ++back;
  }
  return back;
}

// 在[0, n + 1]范围内测试函数正确性与性能.
template <typename FN, typename IR>
void pass(FN find_kth_from_end, IR left, IR right, size_t n)
{
  clock_t start, end;
  start = clock();
  if (find_kth_from_end(left, right, 0) != right)
    cout  << "Error!" << endl;
  for (size_t k = 1; k <= n; ++k)
  {
    auto iter = find_kth_from_end(left, right, k);
    if (iter == right || *iter != k)
      cout << "Error!" << endl;
  }
  if (find_kth_from_end(left, right, n + 1) != right)
    cout  << "Error!" << endl;
  end = clock();
  cout << "运行时间(s): "
       << static_cast<double>(end - start) / static_cast<double>(CLOCKS_PER_SEC)
       << endl;
}

int main()
{
  forward_list<size_t> L;
  size_t n = 10000;
  for (size_t i = 1; i <= n; ++i)
    L.push_front(i);
  pass(count_and_find<decltype(L.begin())>, L.begin(), L.end(), n);
  pass(front_and_back<decltype(L.begin())>, L.begin(), L.end(), n);
  pass(updated_front_and_back<decltype(L.begin())>, L.begin(), L.end(), n);
  pass(mod_updated_front_and_back<decltype(L.begin())>, L.begin(), L.end(), n);
  return 0;
}
