#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

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
    bool isFull();
    bool isEmpty();
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

class Graph{
    struct node{
        int data;
        node* next;
    };
    // vector to store the head pointers of the relations
    vector<node*> ptrToVertices;
public:
    Graph(){}
    ~Graph(){

    }
    void addVertex(int data);
    void deleteVertex(int data);
    void addEdge(int start, int end);
    void deleteEdge(int start, int end);
    void breadthFirstTraversal(int root);
};

void Graph::addVertex(int data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    ptrToVertices.push_back(newNode);
}

void Graph::deleteVertex(int data){
    for(node* vertex : ptrToVertices){
        if(vertex->data == data){
            // delete the linked list associated to that vertex
            while(vertex != NULL){
                vertex = vertex->next;
                free(vertex);
            }
            // remove the vertex from the vector
            ptrToVertices.erase(std::remove(ptrToVertices.begin(),ptrToVertices.end(),vertex),ptrToVertices.end());
            
        }
    }
}

void Graph::addEdge(int start, int end){
    for(node* vertex : ptrToVertices){
        if(vertex->data == start){
            node* newNode = (node*)malloc(sizeof(node));
            newNode->data = end;
            newNode->next = NULL;
            node* temp = vertex;
            while(temp->next != NULL){
                temp = temp->next;
            }temp->next = newNode;
        }
        if(vertex->data == end){
            node* newNode = (node*)malloc(sizeof(node));
            newNode->data = start;
            newNode->next = NULL;
            node* temp = vertex;
            while(temp->next != NULL){
                temp = temp->next;
            }temp->next = newNode;
        }
    }
}

void Graph::deleteEdge(int start, int end){
    for(node* vertex : ptrToVertices){
        if(vertex->data == start){
            node* temp = vertex;
            while(temp->next != NULL){
                if(temp->next->data == end){
                    node* nodeToBeDel = temp->next;
                    temp->next = temp->next->next;
                    free(nodeToBeDel);
                }
            }
            break;
        }
    }
}

void Graph::breadthFirstTraversal(int root){
    CircularQueueLL* queue = new CircularQueueLL();     // dynamically allocate the memory for the queue (circualr queue using LL)
    vector<bool> marked(ptrToVertices.size(), false);   // make vector to store the info whether the node is marked/traversed
    int index = 0;  // find the index of the vertex having data = root
    node* startNode;    // find the vertex having data = root
    // traverse the vector to find vertex with data = root
    for(node* vertex : ptrToVertices){
        if(vertex->data == root){
            startNode = vertex;
            break;
        }index++;
    }

    marked[index] = true;   // mark the index corresponding to the index of the vertex whose data = root as true

    queue->enqueue(root);
    
    cout<<"Breadth First Traversal of graph is: "<<endl;
    
    while(!queue->isEmpty()){
        int vertex = queue->dequeue();
        cout<<vertex<<endl;
        for(node* vertexR : ptrToVertices){
                if(vertexR->data == vertex){
                    startNode = vertexR;
                    break;
                }
            }
        node* temp = startNode->next;     // define a temp variable that points to head of the linked list

        while(temp != NULL){
            index = 0;
            root = temp->data;
            // check whether the adjacent node is already marked or not
            // if marked; pass
            // else: enque 
            for(node* vertex : ptrToVertices){
                if(vertex->data == root){
                    break;
                }index++;
            }
            if(marked[index]);
            else{
                queue->enqueue(root);
                marked[index] = true;
            }
                
            temp = temp->next;
        }
    }
    delete queue;   // deallocate memeory occupied by circular queue
}

void testGraph(){
    Graph* graph = new Graph();
    graph->addVertex(1);
    graph->addVertex(2);
    graph->addVertex(3);
    graph->addVertex(4);
    graph->addVertex(5);
    graph->addVertex(6);
    graph->addVertex(7);
    graph->addVertex(8);
    
    graph->addEdge(1, 2);
    graph->addEdge(1, 5);
    graph->addEdge(2, 6);
    graph->addEdge(3, 6);
    graph->addEdge(3, 4);
    graph->addEdge(3, 7);
    graph->addEdge(4, 7);
    graph->addEdge(4, 8);
    graph->addEdge(6, 7);
    graph->addEdge(7, 8);
    graph->breadthFirstTraversal(2);
    delete graph;   // deallocate the memory occupied by graph
}
int main(){
    testGraph();
    return 0;
}