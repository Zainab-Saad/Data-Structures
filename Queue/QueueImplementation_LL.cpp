#include<iostream>
using namespace std;

class Queue{
private:
    struct node{
        int data;
        node* next;
    };
public:
    node* front;
    node* rear;
    Queue(){
        front = NULL;
        rear = NULL;
    }
    ~Queue(){
        // TODO - deallocate the memory occupied by the LL
    }
    // methods -- no need for isFull() method
    bool isEmpty(){
        return front == NULL;
    }

    void enqueue(int value){
        node* newNode = (node*)malloc(sizeof(node));
        newNode->data = value;
        newNode->next = NULL;
        if(front == NULL){
            front = newNode;
        }else{
            rear->next = newNode;
        }
        rear = newNode;
    }

    int dequeue(){
        if(!isEmpty()){
            if(front->next == NULL)
                rear = NULL;
            node* nodeToBeDel = front;
            int data = nodeToBeDel->data;
            front = front->next;
            free(nodeToBeDel);
            return data;
        }
        return INT_MIN;
    }
    int getFront(){
        if(!isEmpty())
            return front->data;
        return INT_MIN;
    }
    int getPeek(){
        if(!isEmpty())
            return rear->data;
        return INT_MIN;
    }
    void display(){
        node* temp = front;
        for(; temp != NULL; temp = temp->next){
            cout<<temp->data<<endl;
        }
    }
};

void testQueue(){
    // dynamically allocate memroy for the instance of class Queue
    // Queue* queue = (Queue*)malloc(sizeof(Queue)); -- malloc doesnt call the constructor of the class
    Queue* queue = new Queue(); // use new as it calls the constructor of the class
    cout<<"------------"<<endl;
    cout<<"|1|Enqueue |"<<endl;
    cout<<"|2|Dequeue |"<<endl;
    cout<<"|3|Front   | "<<endl;
    cout<<"|4|Peek    |"<<endl;
    cout<<"|5|Display |"<<endl;
    cout<<"|0|Exit    |"<<endl;
    cout<<"------------"<<endl;
    int query;
    cout<<"Enter command "<<endl;
    cin>>query;
    while(query){
        switch(query){
            
            case 1:
                cout<<"Enter value"<<endl;
                int value;
                cin>>value;
                queue->enqueue(value);
                break;
            case 2:
                cout<<"Value dequeued "<<queue->dequeue()<<endl;
                break;
            case 3:
                cout<<"Front is "<<queue->getFront()<<endl;
                break;
            case 4:
                cout<<"Peek is "<<queue->getPeek()<<endl;
                break;
            case 5:
                cout<<"Queue is "<<endl;
                queue->display();
                break;
            default:
                break;
        }
        cout<<"Enter command "<<endl;
        cin>>query;
    }
    delete queue;
}

int main(){
    testQueue();
    return 0;
}