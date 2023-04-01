#include<iostream>
using namespace std;
// circular queue with front = -1 & rear = -1
class CircularQueue{
    int front, rear, size, *queue;
public:
    CircularQueue(int size){
        this->size = size;
        front = rear = -1;
        queue = new int[size];
    }
    ~CircularQueue(){
        delete [] queue;
    }
    void enqueue(int value);
    int dequeue();
    int getFront();
    int getPeek();
    bool isFull();
    bool isEmpty();
    void display();
};

void CircularQueue::enqueue(int val){
    if(!isFull()){
        if(front == -1)
            front++;
        rear = (rear+1) % size;
        queue[rear] = val;
    }
}

int CircularQueue::dequeue(){
    int valToReturn = INT_MIN;
    if(!isEmpty()){
        valToReturn = queue[front];
        if(front == rear)
            front = rear = -1;
        else 
            front = (front+1)%size;
    }
    return valToReturn;
}

bool CircularQueue::isEmpty(){
    return rear == -1;
}

bool CircularQueue::isFull(){
    return (rear+1) % size == front;
}

int CircularQueue::getFront(){
    if(!isEmpty())
        return queue[front];
    return INT_MIN;
}

int CircularQueue::getPeek(){
    if(!isEmpty())
        return queue[rear];
    return INT_MIN;
}

void CircularQueue::display(){
    if(!isEmpty()){
        int i = front;
        while(i != rear){
            cout<<queue[i]<<endl;
            i = (i+1) % size;
        }cout<<queue[rear]<<endl;
    }
}

void testQueue(){
    // dynamically allocate memory for the instance of class Queue
    // Queue* queue = (Queue*)malloc(sizeof(Queue)); -- malloc doesnt call the constructor of the class
    int size = 5;
    CircularQueue* queue = new CircularQueue(size); // use new as it calls the constructor of the class
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
    queue = NULL;
}

int main(){
    testQueue();
    return 0;
}