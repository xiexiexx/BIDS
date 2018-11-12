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
  return 0;
}
