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

void reverseLLIterative(node** head){
    node*temp_2 = NULL, *temp_3 = NULL;
    while((*head) != 0){
        temp_2 = (*head)->next;
        (*head)->next = temp_3;
        temp_3 = *head;
        *head = temp_2;
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
    node* head = NULL;
    cout<<"Original LL"<<endl;
    createLinkedList(&head);
    displayLinkedList(&head);
    cout<<"Reversed List"<<endl;
    reverseLLIterative(&head);
    displayLinkedList(&head);
    return 0;
}