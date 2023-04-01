#include<iostream>
using namespace std;
// declare global variables
// const int sizeOfStack = 5; -- can declare size this way too
# define sizeOfStack 5  // macros definition
int stack[sizeOfStack];
int top = -1;


bool isFull(){
    return top == sizeOfStack - 1;
}
bool isEmpty(){
    return top == -1;
}
void push(int value){
    if(!isFull())
        stack[++top] = value;
    else    
        cout<<"overflow condition"<<endl;
}
int pop(){
    int valuePopped = INT_MIN;
    if(!isEmpty())
        valuePopped = stack[top--];
    return valuePopped;
}
int peek(){
    if(!isEmpty())
        return stack[top]; 
    return INT_MIN;
}
void display(){
    cout<<"Stack is "<<endl;
    for(int i = top; i > -1; i--)
        cout<<stack[i]<<endl;
}
void stackImplementation(){
    cout<<"-----------"<<endl;
    cout<<"|1|Push   |"<<endl;
    cout<<"|2|Pop    |"<<endl;
    cout<<"|3|Peek   | "<<endl;
    cout<<"|4|Display|"<<endl;
    cout<<"|0|Exit   |"<<endl;
    cout<<"-----------"<<endl;
    int query;
    cout<<"Enter command "<<endl;
    cin>>query;
    while(query){
        switch(query){
            case 1:
                int value;
                cout<<"Enter value to push "<<endl;
                cin>>value;
                push(value);
                break;
            case 2:
                cout<<"Value popped "<<pop()<<endl;
                break;
            case 3:
                cout<<"Peek value is "<<peek()<<endl;
                break;
            case 4:
                display();
                break;
            default:
                cout<<"Invalid command"<<endl;
                break;
        }
        cout<<"Enter command "<<endl;
        cin>>query;
    }
}

int main(){
    stackImplementation();
    return 0;
}


