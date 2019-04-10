#include <iostream>
#include <string>

using namespace std;

int main()
{
  string name;
  cin >> name;
  cout << "hello, " << name << endl;
  cout << name.size() << endl;
  name = name + name;
  cout << name << endl;
  string a = "C";
  string b = "++";
  auto c = a + b;
  cout << c << endl;
  return 0;
}
