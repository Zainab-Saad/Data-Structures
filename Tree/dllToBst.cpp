#include<iostream>
#include<cmath>
using namespace std;

struct node{
    int data;
    node* left, *right;
};

node* createDll(int size){
    node* head = NULL, *newNode = NULL, *prevNode = NULL;
    for(int i = 1; i <= size; i++){
        newNode = new node;
        newNode->data = i;
        newNode->left = newNode->right = NULL;
        if(head ==  NULL)
            head = newNode;
        else{
            prevNode->right = newNode;
            newNode->left = prevNode;
        }
        prevNode = newNode;
    }
    return head;
}

int getLengthOfDll(node* head){
    int count = 0;
    node* temp = head;
    while(temp != NULL){
        count++;
        temp = temp->right;
    }
    return count;
}

void displayDll(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<endl;
        temp = temp->right;
    }
}

int getElementOfDll(node* head, int index){
    node* temp = head;
    for(int i = 1;i < index; i++)
        temp = temp->right;
    return temp->data;
}

node* convertDllToBst(node** root, node* head, int start, int end){
    if(end < start)
        return NULL;
    *root = new node;
    (*root)->data = getElementOfDll(head, ceil(float(end+start)/2));
    (*root)->left = (*root)->right = NULL;
    (*root)->left = convertDllToBst(&(*root)->left, head, start, ceil(float(end+start)/2) - 1);
    (*root)->right = convertDllToBst(&(*root)->right, head, ceil(float(end+start)/2) + 1, end);
    return *root;
}

void inorder(node* root){
    if(root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);
}

void preorder(node* root){
    if(root == NULL)
        return;
    cout<<root->data<<endl;
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root){
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<endl;
}


int main(){
    // create a linked list of size 20
    node* headOfDll = createDll(20);
    int length = getLengthOfDll(headOfDll);
    node* rootOfBst = NULL;
    rootOfBst = convertDllToBst(&rootOfBst, headOfDll, 1, length);
    inorder(rootOfBst);
    cout<<"---------------"<<endl;
    preorder(rootOfBst);
    cout<<"---------------"<<endl;
    postorder(rootOfBst);
    return 0;
}