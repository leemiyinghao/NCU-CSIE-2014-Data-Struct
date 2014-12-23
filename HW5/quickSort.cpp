/*
DataStruct HW5-2
by catLee,leemiyinghao@gmx.com
 */
#include<iostream>
using namespace std;
#define MAX_LENGTH 1000

void quickSort(int arr[],int low,int high){
  if(low>=high)
    return;
  int key = arr[low];
  int left = low;
  int right = high+1;
  while(true){
    while(left < high && arr[++left] < key);
    while(right > low && arr[--right] > key);
    if(left<right){
      int tmp = arr[left];
      arr[left] = arr[right];
      arr[right] = tmp;
    }else{
      break;
    }
  }
  int tmp = arr[low];
  arr[low] = arr[right];
  arr[right] = tmp;
  quickSort(arr,low,right-1);
  quickSort(arr,right+1,high);
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
  quickSort(arr,0,ptr-1);
  for(int i = 0;i<ptr;i++){
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}
