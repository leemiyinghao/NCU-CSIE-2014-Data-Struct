/*
DataStruct HW4-2
by catLee,leemiyinghao@gmx.com
*/

#include <iostream>
#include <list>
#include <stack>

using namespace std;

list<int> intList;
struct node{
  node* lchild = NULL;
  node* rchild = NULL;
  int data;
};
void swap(node *a,node *b){
  int tmp = a->data;
  a->data = b->data;
  b->data = tmp;
}
bool compare(node *a,node *b){
  return a->data > b->data;
}
void heapify(node *ptr){
  node* maxNode = ptr;
  if(ptr->lchild)
    maxNode = compare(ptr,ptr->lchild)?ptr:ptr->lchild;
  if(ptr->rchild)
    maxNode = compare(maxNode,ptr->rchild)?maxNode:ptr->rchild;
  if(compare(maxNode,ptr)){
    swap(maxNode,ptr);
    heapify(maxNode);
  }
}
void print_preorder(node *ptr){
  cout << ptr->data << " ";
  if(ptr->lchild != NULL)
    print_preorder(ptr->lchild);
  if(ptr->rchild != NULL)
    print_preorder(ptr->rchild);
}
void travelNode(node* ptr){
  if(ptr->lchild){
    if(ptr->lchild->lchild){
      travelNode(ptr->lchild);
      travelNode(ptr->rchild);
    }
  heapify(ptr);
  }
}
int main(){
  string tmp;
  getline(cin,tmp);
  int tmp_int = 0;
  int dataArr[100] = {};
  int ptr = 0;
  for(int i = 0;i <=tmp.length(); i++){
    if(tmp[i] == ' ' || i == tmp.length()){
      intList.push_back(tmp_int);
      tmp_int = 0;
      continue;
    }
    tmp_int = (tmp_int*10) + ((int)tmp[i]-48);
  }
  node* rootPtr = new node;
  int total = intList.size();
  for(int i = 0;i<total;i++){
    if(i==0){
      rootPtr -> data = intList.front();
      intList.pop_front();
      continue;
    }
    int tmp = (i+1)/2;
    stack<int> path;
    while(tmp>1){
      path.push(tmp%2);
      tmp/=2;
    }
    node* ptr = rootPtr;
    while(!path.empty()){
      int direction = path.top();
      path.pop();
      ptr = (direction==0)?(ptr->lchild):(ptr->rchild);
    }
    if(i%2==1){
      ptr -> lchild = new node();
      ptr -> lchild -> data = intList.front();
    }else{
      ptr -> rchild = new node();
      ptr -> rchild -> data = intList.front();
    }
    intList.pop_front();
  }
  travelNode(rootPtr);
  heapify(rootPtr);
  print_preorder(rootPtr);
  cout << endl;
  return 0;
}
