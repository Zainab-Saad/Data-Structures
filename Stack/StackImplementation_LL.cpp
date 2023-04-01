#include<iostream>
using namespace std;
// push and pop at head in LL
class Stack{
    struct node{
        int data;
        node* next;
    };
    node* top;
public:
    // constructor
    Stack(){
        top = NULL;
    }
    // destructor
    ~Stack(){
        // deallocate memory of stack
        node* temp = top, *temp_2 = NULL;
        while(temp){
            temp_2 = temp->next;
            delete temp;
            temp = temp_2;
        }
        top = NULL;
    }
    //functions on a stack
    void push(int value){
        node* newNode = (node*)malloc(sizeof(node));
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }
    int pop(){
        int valueToBePopped = INT_MIN;
        if(!isEmpty()){
            node* nodeToBeDel = top;
            valueToBePopped = top->data;
            top = top->next;
            delete nodeToBeDel;
        }
        return valueToBePopped;
    }
    int peek(){
        if(!isEmpty())
            return top->data;
        return INT_MIN;
    }
    void display(){
        node* temp = top;
        while(temp){
            cout<<temp->data<<endl;
            temp = temp->next;
        }
    }
    bool isEmpty(){
        return top == NULL;
    }
};

void testStack(){
    // dynamically allocate memory for the stack
    Stack* stack = new Stack();
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
                cout<<"Enter value to push"<<endl;
                cin>>value;
                stack->push(value);
                break;
            case 2:
                cout<<"Value popped is "<<stack->pop();
                break;
            case 3:
                cout<<"Value peeked is "<<stack->peek();
                break;
            case 4:
                cout<<"Display stack"<<endl;
                stack->display();
                break;
            default:
                cout<<"Invalid command"<<endl;
                break;
        }
        cout<<"Enter command "<<endl;
        cin>>query;
    }
    delete stack;
    stack = NULL;
}

int main(){
    testStack();
    return 0;
}