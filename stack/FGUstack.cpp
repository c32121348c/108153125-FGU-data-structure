#include <iostream>
using namespace std;

const int CAPACITY = 5;
int stack1[CAPACITY] = {};
int stack_top = 0;

void push(int i){
    if(i != 0){
        if(stack_top == CAPACITY){
            cout << "stack overflow" << endl;
        }else{
            stack1[stack_top] = i;
            stack_top++;
        }
    }else{
        cout << "元素必須不等於0" << endl;
    }
}
void pop(){
    if(stack_top == 0){
        cout << "stack underflow" << endl;
    }else{
        stack_top--;
        cout << "pop: " << stack1[stack_top] << endl;
    }
}
void top(){
    if(stack_top == 0){
        cout << "NULL" << endl;
    }else{
        cout << "top: " << stack1[stack_top-1] << endl;
    }
}
void peep(int i){
    if(stack_top == 0){
        cout << "NULL" << endl;
    }else{
        cout << "peep " << i << " :" << stack1[stack_top-i] << endl;
    }
}
void empty(){
    stack_top = 0;
}
bool isEmpty(){
    if(stack_top == 0){
        return true;
    }else{
        return false;
    }
}

int main(){
    top();
    push(1);
    push(2);
    top();
    push(3);
    push(4);
    top();
    push(5);
    peep(1);
    peep(2);
    peep(3);
    peep(4);
    peep(5);
    cout << "是否為空: " << isEmpty() << endl;
    pop();
    pop();
    pop();
    pop();
    pop();
    push(99);
    empty();
    cout << "是否為空: " << isEmpty() << endl;
    pop();
    peep(1);

    return 0;
}