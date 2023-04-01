#include<iostream>
using namespace std;
/**
 * @brief KEY NOTES
 * if front = rear; it allows to refill the queue from beginning 
 * but if the front is behind rear and space is empty in the queue;
 * it doesnt allow to enter values in the beginning index which is vacant
 * enqueue = O(1)
 * dequeue = O(1)
 * dequeue = O(n) if allow to refill the vacant indexes when front 
 * is behind the rear
 */
# define sizeOfQueue 5
int queue[sizeOfQueue];
int front = 0, rear = -1;

bool isFull(){
    return rear == sizeOfQueue - 1;
}

bool isEmpty(){
    return rear < front;
}

void enqueue(int value){
    if(!isFull())
        queue[++rear] = value;
}

int dequeue(){
    if(!isEmpty()){
        if(front == rear){
            int valToReturn = queue[front];
            front = 0;
            rear = -1;
            return valToReturn;
        } else{
            return queue[front++];
        }
    }
    return INT_MIN;
}

int getFront(){
    if(!isEmpty())
        return queue[front];
    return INT_MIN;
}

int getPeek(){
    if(!isEmpty())
        return queue[rear];
    return INT_MIN;
}

void display(){
    for(int i = front; i <= rear; i++)
        cout<<queue[i]<<endl;
}

void testQueue(){
    cout<<"-----------"<<endl;
    cout<<"|1|Enqueue |"<<endl;
    cout<<"|2|Dequeue |"<<endl;
    cout<<"|3|Front   | "<<endl;
    cout<<"|4|Peek    |"<<endl;
    cout<<"|5|Display |"<<endl;
    cout<<"|0|Exit    |"<<endl;
    cout<<"-----------"<<endl;
    int query;
    cout<<"Enter command "<<endl;
    cin>>query;
    while(query){
        switch(query){
            case 1:
                cout<<"Enter value "<<endl;
                int value;
                cin>>value;
                enqueue(value);
                break;
            case 2:
                cout<<"Dequeued value "<<dequeue()<<endl;
                break;
            case 3:
                cout<<"Front of queue is "<<getFront()<<endl;
                break;
            case 4:
                cout<<"Peek of queue is "<<getPeek()<<endl;
                break;
            case 5:
                cout<<"Queue is "<<endl;
                display();
                break;
            default:
                break;
        }
        cout<<"Enter command "<<endl;
        cin>>query;
    }
}

int main(){
    testQueue();
    return 0;
}