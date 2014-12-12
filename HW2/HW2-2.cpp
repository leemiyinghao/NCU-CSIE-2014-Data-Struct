#include <iostream>
using namespace std;
int hanoi(int n){
  if(n == 1){
    return 1;
  }else{
    return 2*hanoi(n-1)+1;
  }
}
int main(){
  cout << hanoi(5);
  return 0;
}
