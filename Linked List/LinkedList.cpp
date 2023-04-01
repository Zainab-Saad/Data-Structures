#include <iostream>
using namespace std;
/**
 * @brief linked list implementation asking the user 
 * whether wants to enter another node
 * then display the data stored in the linked list
 */
struct node{
    int data;
    node* next;
}*head, *temp, *newNode;

int calculateLength(){ // give pointer to pointer to head if head nto declared globally
    node* temp = head;  // temp = *head if head not declared globally and not in the class either
    int count = 0;
    while(temp != 0){
        temp = temp->next;
        count++;
    }
    return count;
}

int main(){
    bool choice;    // choice of the user
    head = NULL;    // initially no node created, so head doesnt point to anything
    cout<<"Do you want to enter a node: ";
    cin>>choice;
    while(choice){  // add another node to the linked list
        cout<<endl;
        // allocate a space for new node in the heap and return pointer to starting using malloc or new
        newNode = (node*)malloc(sizeof(node));
        // input data from user
        cout<<"Enter the int data part: ";
        cin>>newNode->data;
        newNode->next = NULL;

        /**
         * @brief new node is formed ------
         * connect it to the linked list
         * if head is null, then head should point to the new node
         * else, take a temp pointer to check which node is having next = NULL, 
         * taht node should point to the new node formed
         * dont disturb head pointer, take a temp variable for tranversing.
         */

        if(head == 0){  // head == NULL
            head = newNode;
        }
        else{
            temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }
        // again take input from the user asking if wants to enter another node
        cout<<endl;
        cout<<"Do you want to enter a node: ";
        cin>>choice;
    }


    // printing the linked list elements
    temp = head;
    while(temp != NULL){
        cout<<temp->data<<endl;
        temp = temp->next;
    }

    cout<<"The length of linked list is "<<calculateLength()<<endl;
    return 1;
}