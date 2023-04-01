#include<iostream>
#include<algorithm>
using namespace std;
class BinarySearchTree{
    struct node{
        int data;
        node* left, *right;
    }*root;
public:
    BinarySearchTree(){
        root = NULL;
    }
    ~BinarySearchTree(){
        // deallocate the memory allocated to nodes in the heap
        freeMemory(&root);
        root = NULL;
    }
    void insert(node**, int);
    bool search(node*, int);
    node* deleteNode(node** root, int val){
        if(*root == NULL)
            return NULL;
        if((*root)->data == val){
            if((*root)->left == NULL && (*root)->right == NULL){
                delete *root;
                return NULL;
            }
            else if((*root)->left ==  NULL){
                node* right = (*root)->right;
                delete *root;
                return right;
            }
            else if((*root)->right == NULL){
                node* left = (*root)->left;
                delete *root;
                return left;
            }
            else{
                int valToBeInserted = findMax((*root)->left);
                *root = deleteNode(root, valToBeInserted);
                (*root)->data = valToBeInserted;
            }

        }
        else if((*root)->data > val)
            (*root)->left = deleteNode(&(*root)->left, val);
        else
            (*root)->right = deleteNode(&(*root)->right, val);
        return *root;
    }
    void inorder(node*);
    void preorder(node*);
    void postorder(node*);
    int findMin(node*);
    int findMax(node*);
    int findHeight(node*);
    node** getRefPtrRoot(){
        return &root;
    }
    bool isBst(node*);
    void freeMemory(node**);
};

void BinarySearchTree::insert(node** root, int val){
    if(*root == NULL){
        *root = (node*)malloc(sizeof(node));
        (*root)->data = val;
        (*root)->left = (*root)->right = NULL;
    }
    else if((*root)->data > val)
        insert(&(*root)->left, val);
    else if((*root)->data < val)
        insert(&(*root)->right, val);
}

bool BinarySearchTree::search(node* root, int val){
    if(root == NULL)
        return false;
    else if(root->data == val)
        return true;
    else if(root->data < val)
        return search(root->right, val);
    else    
        return search(root->left, val);
}

void BinarySearchTree::inorder(node* root){
    if(root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);
}

void BinarySearchTree::preorder(node* root){
    if(root == NULL)
        return;
    cout<<root->data<<endl;
    preorder(root->left);
    preorder(root->right);
}

void BinarySearchTree::postorder(node* root){
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<endl;
}

int BinarySearchTree::findMin(node* root){
    if(root == NULL)
        return INT_MIN;
    else if(root->left == NULL)
        return root->data;
    return findMin(root->left);
}

int BinarySearchTree::findMax(node* root){
    if(root == NULL)    
        return INT_MIN;
    else if(root->right == NULL)
        return root->data;
    return findMax(root->right);
}

int BinarySearchTree::findHeight(node* root){
    if(root == NULL)
        return -1;
    return max(findHeight(root->left), findHeight(root->right)) + 1;
}

bool BinarySearchTree::isBst(node* root){
    if(root == NULL)
        return true;
    if(root->left == 0 && root->right == 0)
        return true;
    else if(root->left == 0 && (root->right)->data > root->data)
        return isBst(root->right);
    else if(root->right == 0 && (root->left)->data < root->data)
        return isBst(root->left);
    else if((root->left)->data < root->data && (root->right)->data > root->data)
        return isBst(root->left) && isBst(root->right);
    return false;
}
void BinarySearchTree::freeMemory(node** root){
    // recursively deallocate memory occupied by the tree 
    if(*root == NULL)
        return;
    freeMemory(&(*root)->left);
    freeMemory(&(*root)->right);
    free(root);
}

void testBinarySearchTree(){
    BinarySearchTree* bst = new BinarySearchTree();
    bool isFound;
    int choice, value;
    while(1)
    {
       cout<<endl<<endl;
       cout<<" Binary Search Tree Operations "<<endl;
       cout<<" ----------------------------- "<<endl;
       cout<<" 1. Insertion/Creation "<<endl;
       cout<<" 2. In-Order Traversal "<<endl;
       cout<<" 3. Pre-Order Traversal "<<endl;
       cout<<" 4. Post-Order Traversal "<<endl;
       cout<<" 5. Removal "<<endl;
       cout<<" 6. Search "<<endl;
       cout<<" 7. Max Element "<<endl;
       cout<<" 8. Min Element "<<endl;
       cout<<" 9. Height "<<endl;
       cout<<" 10.is BST "<<endl;
       cout<<" 11. Exit "<<endl;
       cout<<" Enter your choice : ";
       cin>>choice;
       switch(choice)
       {
           case 1 : cout<<" Enter Number to be inserted : ";
                    cin>>value;
                    bst->insert(bst->getRefPtrRoot(), value);
                    break;
           case 2 : cout<<endl;
                    cout<<" In-Order Traversal "<<endl;
                    cout<<" -------------------"<<endl;
                    bst->inorder(*(bst->getRefPtrRoot()));
                    break;
           case 3 : cout<<endl;
                    cout<<" Pre-Order Traversal "<<endl;
                    cout<<" -------------------"<<endl;
                    bst->preorder(*(bst->getRefPtrRoot()));
                    break;
           case 4 : cout<<endl;
                    cout<<" Post-Order Traversal "<<endl;
                    cout<<" --------------------"<<endl;
                    bst->postorder(*(bst->getRefPtrRoot()));
                    break;
           case 5 : cout<<" Enter data to be deleted : ";
                    cin>>value;
                    bst->deleteNode(bst->getRefPtrRoot(), value);
                    break;
           case 6:  cout<<" Enter data to be deleted : ";
                    cin>>value;
                    isFound = bst->search(*(bst->getRefPtrRoot()), value);
                    cout<<"Found = "<<isFound<<endl;
                    break;
           case 7 : cout<<endl;
                    cout<<"Max element is "<<bst->findMax(*(bst->getRefPtrRoot()))<<endl;
                    break;
           case 8 : cout<<endl;
                    cout<<"Min element is "<<bst->findMin(*(bst->getRefPtrRoot()))<<endl;
                    break;
           case 9 : cout<<endl;
                    cout<<"Heigth of tree is "<<bst->findHeight(*(bst->getRefPtrRoot()))<<endl;
                    break;
           case 10: cout<<endl;
                    cout<<"is bst? "<<bst->isBst(*(bst->getRefPtrRoot()))<<endl;
           case 11 : system("pause");
                    break;
                    break;
       }
    }
    delete bst; // free the memory occupied by the object & call the destructor
                // to free the memory occupied by the tree.
}


int main()
{
    testBinarySearchTree();
    return 0;
}