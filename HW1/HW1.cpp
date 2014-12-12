#include <iostream>
#include <string>
#define MAX 1000
#define EMPTY -1
using namespace std;

struct stack{
  char data[MAX];
  int top;
};

void push(char c,stack *st){
  if(st->top < MAX){
    st->data[++st->top] = c;
  }
}
char pop(stack *st){
  if(st->top < MAX){
    return st->data[st->top--];
  }else{
    return '\0';
  }
}
bool isempty(stack *st){
  return st->top <= EMPTY;
}
int main(){
  stack *st = new stack();
  return 0;
}
