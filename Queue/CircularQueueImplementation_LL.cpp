#include<iostream>
using namespace std;
/**
 * @brief 
 * implementation of circular queue using LL is equivalent to 
 * implementing FIFO principle for insertion and deletion in circular LL
 * code can be more optimized by considering only the rear variable, and eliminating the front variable
 * @return int 
 */
class CircularQueueLL{
    struct node{
        int data;
        node* next;
    };
    node* front, *rear;
public:
    CircularQueueLL(){
        front = rear = NULL;
    }
    ~CircularQueueLL(){
        // deallocate the memory occupied by the nodes
        node* temp = front, *temp_2 = NULL;
        while(temp != rear){
            temp_2 = temp->next;
            delete temp;
            temp = temp_2;
        } delete temp;
        front = rear = temp = temp_2 = NULL;
    }
    void enqueue(int value);
    int dequeue();
    int getFront();
    int getPeek();
    bool isFull();
    bool isEmpty();
    void display();
};

void CircularQueueLL::enqueue(int val){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = val;
    if(front == NULL)
        front = rear = newNode;
    else{
        rear->next = newNode;
        rear = newNode;
    }
    rear->next = front; // because it is circular LL
}

int CircularQueueLL::dequeue(){
    int valToReturn = INT_MIN;
    if(!isEmpty()){
        valToReturn = front->data;
        if(front == rear){
            delete front;   // free space of the only left node on the heap space
            front = rear = NULL;
        }else{
            node* nodeToBeDel = front;
            front = front->next;
            rear->next = front;
            delete nodeToBeDel;
        }
    }
    return valToReturn;
}

bool CircularQueueLL::isEmpty(){
    return front == NULL;
}

int CircularQueueLL::getFront(){
    if(!isEmpty())
        return front->data;
    return INT_MIN;
}

int CircularQueueLL::getPeek(){
    if(!isEmpty())
        return rear->data;
    return INT_MIN;
}

void CircularQueueLL::display(){
    if(!isEmpty()){
        node* temp = front;
        while(temp->next != front){
            cout<<temp->data<<endl;
            temp = temp->next;
        }cout<<temp->data<<endl;
    }
}

void testQueue(){
    CircularQueueLL* queue = new CircularQueueLL(); // use new as it calls the constructor of the class
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