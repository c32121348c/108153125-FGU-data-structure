#include <iostream>
using namespace std;

const int A = 10;
int queue[A] = {};
int head = 0;
int tail = 0;

void lookHead(){
    cout << "佇列最前端: " << queue[head] << endl;
}
void lookTail(){
    cout << "佇列最後端: " << queue[tail-1] << endl;
}
void peep(int i){
    cout << "佇列第" << i << "為: " << queue[i] << endl;
}
void empty(){
    for(int i=0; i<A; i++){
        queue[i] = 0;
    }
    cout << "佇列已清空" << endl;
}
void dequeue(){
    if(head == tail){
        cout << "佇列已空" << endl;
    }else{
        cout << "取出: " << queue[head] << endl;
        queue[head] = 0;
        head = (head + 1) % A;
    }
}
void enqueue(int i){
    if(head == (tail + 1) % A){
        cout << "佇列已滿" << endl;
    }else{
        queue[tail] = i;
        tail = (tail + 1) % A;
    }
}
void printQueue(){
    for(int i=0; i<A; i++){
        cout << queue[i] << "\t";
    }
    cout << endl;
}

int main(){
    enqueue(99);
    enqueue(99);
    enqueue(99);
    enqueue(99);
    enqueue(999);
    enqueue(999);
    enqueue(999);
    enqueue(999);
    enqueue(999);
    enqueue(999);
    printQueue();
    dequeue();
    dequeue();
    dequeue();
    printQueue();
    lookHead();
    lookTail();
    enqueue(1);
    enqueue(1);
    printQueue();
    lookHead();
    lookTail();
}