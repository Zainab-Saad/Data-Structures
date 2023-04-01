#include <iostream>
using namespace std;

class Node{
public:
    int coff = 0;
    int exp = 0;
    Node* next = NULL;
};

class LinkedList {
    private:
        int size_;
        Node *head_ = NULL;
        Node *tail_ = NULL;
        Node *itr_ = NULL;

    public:
    LinkedList() {
        this->size_ = 0;
    }

    //inserts value at the end
    void append(int coff, int exp) {
        //write your code here
        // create a new node
        Node* newNode = (Node*)(malloc(sizeof(Node)));
        newNode->coff = coff;
        newNode->exp = exp;
        newNode->next = NULL;
        // append to linked list
        if(tail_ == 0){
            head_ = newNode;
            tail_ = newNode;
        }else{
            tail_->next = newNode;
            tail_ = newNode;
        } 
        size_++;
    }


    Node* iterate() { //iterates and returns each node
        if (this->itr_ == NULL)  {
            this->itr_ = this->head_;
        }  else {
            this->itr_ = (this->itr_)->next;
        }  return this->itr_;
    }

    
    //traverses through the nodes and displays the values of all the nodes
    void displayList(){
        // write your code here
        while(iterate() != 0){
            cout<<itr_->coff<<"x^"<<itr_->exp<<" ";
        }  cout<<endl;
    }
    void sortedInsert(Node** head, Node* newNode){
        if(*head != 0){
                if(newNode->exp >= (*head)->exp){
                newNode->next = (*head);
                (*head) = newNode;
                return;
            }
            Node* temp = *head;
            while(temp->next != 0){
                if(newNode->exp >= (temp->next)->exp){
                    newNode->next = temp->next;
                    temp->next = newNode;
                    return;
                }temp = temp->next;
            }
            temp->next = newNode;
        }else{
            *head = newNode;
        }
    }

    void SortLinkedList(){
        Node* newHead = NULL;
        while(this->head_ != 0){
            Node* temp = (this->head_)->next;
            this->head_->next = NULL;
            sortedInsert(&newHead, head_);
            this->head_ = temp;
        }this->head_ = newHead;
        newHead = NULL;
    }
};

int returnCoffForNewNode(Node** temp){
    // new nodes coff is zero at the moment
    int expValue = (*temp)->exp;
    int coffecient = 0;
    while((*temp) != 0 && (*temp)->exp == expValue){
        coffecient += (*temp)->coff;
        (*temp) = (*temp)->next;
    } return coffecient;
}

LinkedList addPolynomials(LinkedList p1, LinkedList p2){
    // inputs sorted linked lists that may contain duplicate exponents 
    LinkedList addedList;
    Node* p1Node = p1.iterate();
    Node* p2Node = p2.iterate();
    //Iterates over both lists and add and appends according to condition
    //write your code here
    while(p1Node != 0 && p2Node != 0){
        if(p1Node->exp > p2Node->exp){
        addedList.append(returnCoffForNewNode(&p1Node), p1Node->exp);
        } else if(p1Node->exp < p2Node->exp){
            addedList.append(returnCoffForNewNode(&p2Node), p2Node->exp);
        } else{
            int exponent = p1Node->exp;
            int cofficient = returnCoffForNewNode(&p1Node) +  returnCoffForNewNode(&p2Node);
            addedList.append(cofficient, exponent);
        }
    }
    if(p1Node == 0 && p2Node != 0){
        while(p2Node != 0){
            int exponent = p2Node->exp, cofficient = returnCoffForNewNode(&p2Node);
            addedList.append(cofficient, exponent);
        }
    } else if(p1Node != 0 && p2Node == 0){
        while(p1Node != 0){
            int exponent = p1Node->exp, cofficient = returnCoffForNewNode(&p1Node);
            addedList.append(cofficient, exponent);
        }
    } return addedList;
}

//Takes user input
void TakeUserInput(LinkedList &list){
    int flag = 1;
    
    while(flag) {
    int coff = 0;
    int exp = 0;
    cout << "Enter coff: ";
    cin >> coff;    
    cout << "Enter exp: ";
    cin >> exp;
    list.append(coff, exp);
    cout << "Enter 1 to continue, Enter 0 to exit: ";
    cin >> flag;    
    } 
}

int main() {
    cout << "Enter input for List 1" << endl;
    LinkedList list1;
    TakeUserInput(list1);
    list1.SortLinkedList();
    list1.displayList();

    cout << "Enter input for List 2" << endl;
    LinkedList list2;
    TakeUserInput(list2);
    list2.SortLinkedList();
    list2.displayList();

    cout << "The added polynomials are" << endl;
    LinkedList added = addPolynomials(list1, list2);
    added.displayList();
    return 0;
}