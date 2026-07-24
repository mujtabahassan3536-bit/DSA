#include <iostream>
using namespace std;

class circularQueue
{
private:
int *arr;
int front;
int rear;
int capacity;
int currentSize;
public:
circularQueue(int size){
 front=0;
 rear=-1;
 capacity=size;
 arr=new int[capacity];
 currentSize=0;

}
void push(int value){
 if(currentSize==capacity){
    cout<<"Queue overflow"<<endl;
    return;
    }
   rear=(rear+1)%capacity;
   arr[rear]=value; 
   currentSize++;
 }
int frontElement()
{
    if (currentSize == 0)
    {
        cout << "Queue is Empty!" << endl;
        return -1;
    }

    return arr[front];
}
void pop(){
    if(currentSize==0){
        cout<<"Queue emptry"<<endl;
    return;
    }
    front=(front+1)%capacity;
    currentSize--;
}
bool empty(){
     return currentSize == 0;
}
void print() {
    if (empty()) {
        cout << "Queue Khali Hai!" << endl;
        return;
    }

    int index = front; 
    for (int i = 0; i < currentSize; i++) {
        cout << arr[index] << " ";
        index = (index + 1) % capacity; 
    }
    cout << endl;
}
 ~circularQueue() {
        delete[] arr; 
    }
};
int main (){
  circularQueue cq(5);
  cq.push(1);
  cq.push(2);
  cq.push(3);
  cq.pop();  
  cq.push(4);
  cq.print();
   return 0;
}
