/*
DataStruct HW4-1
by catLee,leemiyinghao@gmx.com
*/

#include <iostream>
#include <string>
#include <list>

#define MAX_CHR 9

using namespace std;
struct node{
  node* lchild;
  node* rchild;
  int chr;
  int weight;
};
list<node*> nodeList;
int compare(node *a,node *b){
  return a->weight > b->weight;
}
string codeArr[MAX_CHR] = {""};
void encode(node* ptr,string code){
  if(ptr->chr >= 0){
    codeArr[ptr->chr] = code;
  }else{
    encode(ptr->lchild,code+"0");
    encode(ptr->rchild,code+"1");
  }
}
node* ptr;
string charArr[MAX_CHR] = {"A : ","B : ","C : ","D : ","E : ","F : ","G : ","H : ","I : "};
int main(){
  for(int i = 0;i<MAX_CHR;i++){
    int tmp;
    cout << charArr[i];
    cin >> tmp;
    ptr = new node;
    ptr -> chr = i;
    ptr -> weight = tmp;
    nodeList.push_back(ptr);
  }
  while(nodeList.size()>1){
    nodeList.sort(compare);
    ptr = new node;
    ptr -> chr = -1;
    ptr -> weight = 0;
    ptr -> lchild = nodeList.back();
    ptr -> weight += nodeList.back() -> weight;
    nodeList.pop_back();
    ptr -> rchild = nodeList.back();
    ptr -> weight += nodeList.back() -> weight;
    nodeList.pop_back();
    nodeList.push_back(ptr);
  }
  encode(nodeList.back(),"");
  for(int i = 0;i<MAX_CHR;i++){
    cout << charArr[i] << codeArr[i] << endl;
  }
  return 0;
}
//I hate C++.
