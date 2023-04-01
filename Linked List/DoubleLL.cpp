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

void displayLL(node* head){
    node* temp = head;
    // print the data in forward direction
    while(temp != 0){
        cout<<"The node data is "<<temp->data<<" "<<temp->prev<<" "<<temp->next<<endl;
        temp = temp->next;
    }
    // print the data in backward direction
    // while(temp->next != 0){
    //     temp = temp->next;
    // }
    // while(temp != 0){
    //     cout<<temp->data<<endl;
    //     temp = temp->prev;
    // }

}
int main(){
    node* head = NULL;
    createLL(&head, 5);
    displayLL(head);
    
    return 0;
}