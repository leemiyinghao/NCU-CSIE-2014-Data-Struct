#include <iostream>
#include <string>
#define MAX 1000
#define EMPTY 0
using namespace std;

struct stack{
  char data[MAX];
  int top;
};

void push(char c,stack *st){
  if(st->top < MAX){
    st->data[st->top++] = c;
  }
}
char pop(stack *st){
  if(st->top < MAX){
    return st->data[--st->top];
  }else{
    return ' ';
  }
}
bool isempty(stack *st){
  return st->top <= EMPTY;
}
void infix2postfix(string func){
  stack *st = new stack();
  st->top = 0;
  for(int i = 0;i<func.length();i++){
    if(func[i] == '+' || func[i] == '-' || func[i] == '*' || func[i] == '/' || func[i] == '('){
      push(func[i],st);
    }else if(func[i] == ')'){
      for(char ch = ')';ch != '(';ch = pop(st)){
	if(ch!='(' && ch!=')')
	  cout << ch;
      }
    }else{
      cout << func[i];
    }
  }
  /*
  for(char ch = pop(st);ch != ' ';ch = pop(st)){
    cout << ch;
  }
  */
  while(!isempty(st)){
    cout << pop(st);
  }
}

int main(){
  string str = "";
  cin >> str;
  infix2postfix(str);
  cout << endl;
  return 0;
}
