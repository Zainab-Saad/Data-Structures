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

void deleteAtbeginning(node** head){
    if(*head == 0);
    else{
        node* temp = *head;
        *head = (*head)->next;
        delete temp;
    }
}
void deleteAtEnd(node** head){
    if(*head == 0);
    else{
        if((*head)->next == 0){
            node* nodeToBeDel = *head;
            delete nodeToBeDel;
            *head = NULL;
        }else{
            node* temp = *head;
            while((temp->next)->next != 0)
                temp = temp->next;
            node* temp_2 = temp->next;
            temp->next = NULL;
            delete temp_2;
        }

    }

}
void deleteAfter(node** head, int val){
    node* temp = *head;
    while(temp->next != 0){
        if(temp->data == val){
            node* nodeToBeDel = temp->next;
            temp->next = (temp->next)->next;
            delete nodeToBeDel;
        }if(temp->next == 0) break;
        temp = temp->next;
    }
}
void deleteBefore(node** head, int val){
    if(((*head)->next)->data == val){
        node* nodeToBeDel = (*head);
        *head = (*head)->next;
        delete nodeToBeDel;
    }
    node* temp = *head;
    while((temp->next)->next != 0){
        if(((temp->next)->next)->data == val){
            node* nodeToBeDel = temp->next;
            temp->next = (temp->next)->next;
            delete nodeToBeDel;
        }
        temp = temp->next;
        if((temp->next) == 0){
            break;
        }
    }
}
void deleteAt(node** head, int index){
    int count = -1;
    node* temp = *head;
    while(temp != 0){
        if(count + 1 == index){
            node* nodeToBeDel = NULL;
            if(count+1 == 0){
                nodeToBeDel = *head;
                *head = (*head)->next;
                delete nodeToBeDel;
                break;
            }
            nodeToBeDel = temp->next;
            temp->next = (temp->next)->next;
            delete nodeToBeDel;
            break;
        }count++;
        if(count != 0)
            temp = temp->next;
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
    // create and display linked list
    createLinkedList(&head);
    cout<<"original LL"<<endl;
    displayLinkedList(&head);
    // test functions
    deleteAtEnd(&head);

    cout<<"modified LL"<<endl;
    displayLinkedList(&head);
    return 0;
}