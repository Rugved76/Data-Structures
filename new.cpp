#include <iostream>
using namespace std;

int main() {
  int n,d,result;
  cout << "enter numbers "<<endl;
  cin >> n>>d;
  try
  {
      if(d==0){
          throw d;
      }
  int result = n/d;
  }
  catch(int ex)
  {
      cout<< "division by zero is not allowed \n"<<ex;
  }
  cout <<"division is "<< result;
  return 0;
}
