#include <iostream>

using namespace std;

class Queue{
public:
  Queue(int max){
    array = new char[max];
    _max = max;
    front = -1;
    rear = -1;
  };
  bool isempty(){
    return front == rear;
  }
  bool isfull(){
    return rear == (front + 1)%_max;
  }
  char delet(){
    if(!isempty())
      return array[++rear];
    return '\0';
  }
  bool add(char ch){
    if(!isfull()){
      array[++front] = ch;
      return true;
    }
    return false;
  }
  void print(){
    cout << "front: " << front << " rear: " << rear << endl;
    for(int i = rear+1;i<=front;i++)
      cout << array[i];
    cout << endl;
  }
private:
  int _max;
  char* array;
  int front,rear;
};
int main(void){
  Queue q(10);
  q.print();
  q.add('h');
  q.add('e');
  q.add('l');
  q.add('l');
  q.add('o');
  q.print();
  cout << q.delet() << endl;
  cout << q.delet() << endl;
  cout << q.delet() << endl;
  cout << q.delet() << endl;
  q.print();
  cout << q.delet() << endl;
  q.print();
  return 0;
}
