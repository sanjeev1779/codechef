// extract to string
#include <iostream>
#include <string>
using namespace std;
main ()
{
  std::string name;

  std::cout << "Please, enter your full name: ";
  std::getline (std::cin,name);
  int j;
  cin>>j;
  cout<<j<<endl;
  std::cout << "Hello, " << name << "!\n";

  return 0;
}
