/*
DataStruct HW5-3
by catLee,leemiyinghao@gmx.com
*/
#include <iostream>
#include <math.h>
using namespace std;
#define MAX_LENGTH 1000

int arr[MAX_LENGTH] = {0};
int length = 0;
void Swap(int a,int b){
  int tmp = arr[b];
  arr[b] = arr[a];
  arr[a] = tmp;
}
void heapAdjust(int i,int j){
  int largest = i;
  int left = 2*i + 1;
  int right = 2*i + 2;
  if (left < j && arr[largest] < arr[left]) {
    largest = left;
  }

  if (right < j && arr[largest] < arr[right]) {
    largest = right;
  }

  if (largest != i) {
    Swap(i, largest);
    heapAdjust(largest, j);
  }
}
void buildMaxHeap(){
  for (int i = floor(length/2) -1; i >= 0; i--) {
    heapAdjust(i, length);
  }
}
void heapSort(){
  buildMaxHeap();
  for(int i = length-1;i>0;i--){
    Swap(0,i);
    heapAdjust(0,i);
  }
}
int main(){
  string tmp;
  getline(cin,tmp);
  int tmp_int = 0;
  int ptr = 0;
  for(int i = 0;i <=tmp.length(); i++){
    if(tmp[i] == ' ' || i == tmp.length()){
      arr[ptr++] = tmp_int;
      tmp_int = 0;
      continue;
    }
    tmp_int = (tmp_int*10) + ((int)tmp[i]-48);
  }
  length = ptr;
  heapSort();
  for(int i = 0;i<ptr;i++){
    cout << arr[i] << " ";
  }
  cout << endl;
}
