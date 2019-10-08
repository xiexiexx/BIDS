#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

template <typename T>
void print_buckets(const unordered_set<T>& S)
{
  for (size_t i = 0; i < S.bucket_count(); ++i)
  {
    cout << "Bucket " << i << ": ";
    for (auto iter = S.begin(i); iter != S.end(i); ++iter)
      cout << *iter << ' ';
    cout << endl;
  }
}

int main()
{
  vector<int> V = {7, 4, 3, -6, 5, 4, 22, 71, 42, -96, 81, 12, 105};
  unordered_set<int> S(V.begin(), V.end());
  S.insert(23);
  S.erase(5);
  print_buckets(S);
  for (auto iter = S.begin(); iter != S.end(); ++iter)
    cout << *iter << ' ';
  cout << endl;
  auto iter = S.begin();
  while (iter != S.end())
    if (*iter % 2 == 0)
      iter = S.erase(iter);
    else
      ++iter;
  for (const auto& x : S)
    cout << x << ' ';
  cout << endl;
  print_buckets(S);
  cout << "Max Load Factor: " << S.max_load_factor() << endl;
  cout << "Load Factor: " << S.load_factor() << endl;
  S.max_load_factor(0.5);
  for (const auto& x : V)
    S.insert(-x);
  print_buckets(S);
  cout << "Max Load Factor: " << S.max_load_factor() << endl;
  cout << "Load Factor: " << S.load_factor() << endl;
  return 0;
}
