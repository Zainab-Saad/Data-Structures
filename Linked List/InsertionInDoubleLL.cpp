#include<iostream>
using namespace std;
struct node{
    int data;
    node* prev, *next;
};

void createLL(node** head, int length){
    // create double circular linked list of length number of nodes
    for(int i = 0; i < length; i++){
        node* newNode = (node*)malloc(sizeof(node));
        newNode->prev = NULL;
        newNode->next = NULL;
        newNode->data = i+10;
        if(*head == 0){
            *head = newNode;
        }
        else{
            node* temp = *head;
            while(temp->next != 0){
                temp = temp->next;
            }
            newNode->prev = temp;
            temp->next = newNode;
        }
    }
}

void insertionAtBeginning(node** head, int val){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}
void insertionAtEnd(node** head, int val){
    node* newNode = (node*)malloc(sizeof(node)), *temp = *head;
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = NULL;
    while(temp->next != 0){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}
void insertAfter(node** head, int val1, int val2){
    node* temp = *head;
    while(temp != 0){
        if(temp->data == val1){
            node* newNode = (node*)malloc(sizeof(node));
            newNode->data = val2;
            newNode->prev = temp;
            newNode->next = temp->next;
            if(temp->next != 0) (temp->next)->prev == newNode;
            temp->next = newNode;
        }
        temp = temp->next;
    }

}
void insertBefore(node** head, int val1, int val2){
    node* temp = *head;
    while(temp != 0){
        if(temp->data == val1){
            node* newNode = (node*)malloc(sizeof(node));
            newNode->data = val2;
            newNode->prev = temp->prev;
            if(temp == *head) *head = newNode;
            else (temp->prev)->next = newNode;
            newNode->next = temp;
            temp->prev = newNode;
        }
        temp = temp->next;
    }
}
void insertAt(node** head, int index, int val){
    int count = 0;
    node* temp = *head;
    while(temp != 0){
        if(count == index){
            node* newNode = (node*)malloc(sizeof(node));
            newNode->data = val;
            newNode->next = temp;
            newNode->prev = temp->prev;
            if(temp == *head) *head = newNode;
            else (temp->prev)->next = newNode;
            temp->prev = newNode;
        }
        count++;
        temp = temp->next;
    }
}

void displayLL(node* head){
    node* temp = head;
    // print the data in forward direction
    while(temp != 0){
        cout<<"The node data is "<<temp->data<<" "<<temp->prev<<" "<<temp->next<<endl;
        temp = temp->next;
    }
}

int main(){
    node* head = NULL;
    cout<<"Original LL"<<endl;
    createLL(&head, 5);
    displayLL(head);
    cout<<"Modified LL"<<endl;
    insertAt(&head, 5, -10);
    displayLL(head);

    return 0;
}