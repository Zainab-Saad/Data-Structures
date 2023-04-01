#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

void createLinkedList(node** head){
    for(int i = 0; i < 5; i++){
        node* newNode, *temp;
        // create a new node
        newNode = (node*)malloc(sizeof(node));
        newNode->data = i+100;
        newNode->next = NULL;

        // link the new node to the linked list
        if(*head == NULL){
            // store the pointer to the first node into the head
            *head = newNode;
        }
        else{
            temp = *head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

void insertionAtBeginning(node** head, int val){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = val;
    if(*head == 0){
        *head = newNode;
        (newNode)->next = NULL;
    }
    else{
        (newNode)->next = *head;
        *head = newNode;
    }
    
}

void insertionAtEnd(node** head, int val){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = val;
    if(*head == 0){
        *head = newNode;
        (newNode)->next = NULL;
    }
    else{
        node* temp = *head;
        while(temp->next != 0){
            temp = temp->next;
        }
        temp->next = newNode;
        (newNode)->next = NULL;
    }
}

void insertAfter(node** head, int val1, int val2){
    if(*head == 0);
    else{
        node* temp; // for tranversal
        temp = *head;
        while(temp != 0){   // loop till theh last node
            if(temp->data == val1){
                node* newNode = new node;   // make the new node with the data val2
                newNode->data = val2;
                newNode->next = temp->next;
                temp->next = newNode;
            }temp = temp->next;
        }
    }
}
void insertBefore(node** head, int val1, int val2){
    node* temp =  *head, *newNode = NULL;
    if((*head)->data == val1){
        newNode = new node;
        newNode->data = val2;
        newNode->next = *head;
        *head = newNode;
    }
    while(temp->next != 0){
        if((temp->next)->data == val1){
            newNode = new node;
            newNode->data = val2;
            newNode->next = temp->next;
            temp->next = newNode;

            // change the temp
            temp = (temp->next)->next;
        }else{
            temp = temp->next;
        }
    }
}
void insertAt(node** head, int index, int val){
    node* newNode = new node;
    newNode->data = val;
    newNode->next = NULL;
    // assume the index of ll starts at 0
    if(index == 0){
        if(*head == 0){
            *head = newNode; 
        }else{
            newNode->next = *head;
            *head = newNode;
        }
    }else
    {
        node* temp = *head;
        int count = 1;
        while(temp != 0){
            if(count == index){
                newNode->next = temp->next;
                temp->next = newNode;
            }count++;
            temp = temp->next;
        }
    }
}

void displayLinkedList(node** head){
    node* temp = *head;
    while(temp != NULL){
        cout<<temp->data<<endl;
        temp = temp->next;
    }
}


int main(){
    node* head;
    head = NULL;
    // insert three nodes in a linked list
    createLinkedList(&head);
    //print the LL
    cout<<"original LL "<<endl;
    displayLinkedList(&head);
    /**
     * @brief check the funtions made above here
     * 
     */
    insertAt(&head, -1, -100);
    //display LL
    cout<<"changed LL"<<endl;
    displayLinkedList(&head);
    return 0;
}