/*
DataStruct HW5-1
by catLee,leemiyinghao@gmx.com
*/

#include <iostream>
using namespace std;
#define MAX_LENGTH 1000

void bubbleSort(int arr[],int length){
  for(int i = length-1;i>0;i--){
    for(int j = 0;j<i-1;j++){
      if(arr[j]>arr[j+1]){
	int temp = arr[j];
	arr[j] = arr[j+1];
	arr[j+1] = temp;
      }
    }
  }
}
int main(){
  string tmp;
  getline(cin,tmp);
  int tmp_int = 0;
  int ptr = 0;
  int arr[MAX_LENGTH] = {0};
  for(int i = 0;i <=tmp.length(); i++){
    if(tmp[i] == ' ' || i == tmp.length()){
      arr[ptr++] = tmp_int;
      tmp_int = 0;
      continue;
    }
    tmp_int = (tmp_int*10) + ((int)tmp[i]-48);
  }
  bubbleSort(arr,ptr+1);
  for(int i = 0;i<ptr;i++){
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}
