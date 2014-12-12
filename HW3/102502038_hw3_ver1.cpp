/*
DataStruct HW3
by catLee,leemiyinghao@gmx.com
*/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class treeNode{
private:
  treeNode *leftChild;
  treeNode *rightChild;
  int data;
public:
  treeNode(int _data){
    data = _data;
    leftChild = NULL;
    rightChild = NULL;
  }
  void addNode(int _data){
    if((_data<data?leftChild:rightChild) == NULL){
      (_data<data?leftChild:rightChild) = new treeNode(_data);
    }else{
      (_data<data?leftChild:rightChild) -> addNode(_data);
    }
  }
  void getinorder(){
    if(leftChild)
      leftChild->getinorder();
    cout << data << " ";
    if(rightChild)
      rightChild->getinorder();
  } 
  void getpostorder(){
    if(rightChild)
      rightChild->getpostorder();
    if(leftChild)
      leftChild->getpostorder();
    cout << data << " ";
  } 
  void getpreorder(){
    cout << data << " ";
    if(leftChild)
      leftChild->getpreorder();
    if(rightChild)
      rightChild->getpreorder();
  } 
};

int main(){
  string tmp;
  getline(cin,tmp);
  int tmp_int = 0;
  int dataArr[100] = {};
  int ptr = 0;
  for(int i = 0;i <=tmp.length(); i++){
    if(tmp[i] == ' ' || i == tmp.length()){
      dataArr[ptr++] = tmp_int;
      tmp_int = 0;
      continue;
    }
    tmp_int = (tmp_int*10) + ((int)tmp[i]-48);
  }
  treeNode root(dataArr[0]);
  for(int i = 1;i<ptr;i++){
    root.addNode(dataArr[i]);
  }
  cout << "inorder: ";
  root.getinorder();
  cout << endl << "postorder: ";
  root.getpostorder();
  cout << endl << "preorder: ";
  root.getpreorder();
  cout << endl;
  return 0;
}
