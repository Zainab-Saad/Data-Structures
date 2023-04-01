// AVL tree implementation in C++

# include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node *left;
    Node *right;
    int height;
};

// int max(int a, int b);

// Calculate height
int height(Node *node) {
  if (node == NULL)
    return 0;
  return node->height;
}

int max(int a, int b) {
  return (a > b) ? a : b;
}

// New node creation
Node *newNode(int value) {
  Node *node = new Node();
  node->value = value;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return (node);
}

// Rotate right
Node *rightRotate(Node *y) {
  Node *x = y->left;
  Node *Temp = x->right;
  x->right = y;
  y->left = Temp;
  // Assigning New Heights
  y->height = 1 + max(height(y->left),height(y->right));
  x->height = 1 + max(height(x->left),height(x->right));
  return x;
}

// Rotate left
Node *leftRotate(Node *y) {
  Node *x = y->right;
  Node *temp = x->left;
  x->left = y;
  y->right = temp;
  // Assigning New Heights
  y->height = 1 + max(height(y->left),height(x->right));
  x->height = 1 + max(height(x->left), height(x->right));
  return x;
}

// Get the balance factor of each node
int getBalanceFactor(Node *N) {
  if (N == NULL)
    return 0;
  return height(N->left) -
       height(N->right);
}

// Insert a node
Node *insertNode(Node *node, int value) {
  // Find the correct postion and insert the node
  if (node == NULL)
    return (newNode(value));
  if (value < node->value)
    node->left = insertNode(node->left, value);
  else if (value > node->value)
    node->right = insertNode(node->right, value);
  else  // if the recursion reached the root node, then simply return the root node
    return node;

  // Update the balance factor of each node and
  // balance the tree by rotations
  node->height = 1 + max(height(node->left),
               height(node->right));
  int balanceFactor = getBalanceFactor(node);
  if (balanceFactor > 1) {
    if (value < node->left->value){ // Condition For LL Imbalance so to fix it we Right Rotate it 
      return rightRotate(node);
    } 
    else if (value > node->left->value){  // Condtion for LR Rotation
      node->left = leftRotate(node->left);
      return rightRotate(node); 
    }
  }
  if (balanceFactor < -1) {
    if (value > node->right->value) {  // Condition For RR Imbalance so to fix it we Left Rotate it
      return leftRotate(node);
    } else if (value < node->right->value) {  // Condtion for RL Rotation
      node->right = rightRotate(node->right);
      return leftRotate(node);
    }
  }
  return node;
}

// Node with minimum value
Node *nodeWithMimumValue(Node *node) {
  Node *current = node;
  while (current->left != NULL)
    current = current->left;
  return current;
}

// Delete a node
Node *deleteNode(Node *root, int value) {
  // Find the node and delete it
  if (root == NULL)
    return root;
  if (value < root->value)
    root->left = deleteNode(root->left, value);
  else if (value > root->value)
    root->right = deleteNode(root->right, value);
  else {
    if ((root->left == NULL) ||
      (root->right == NULL)) {
      Node *temp = root->left ? root->left : root->right;
      if (temp == NULL) {
        temp = root;
        root = NULL;
      } 
      else
        *root = *temp;
      free(temp);
    } else {
      Node *temp = nodeWithMimumValue(root->right);
      root->value = temp->value;
      root->right = deleteNode(root->right,
                   temp->value);
    }
  }

  if (root == NULL)
    return root;

  // Update the balance factor of each node and
  // balance the tree
  root->height = 1 + max(height(root->left),
               height(root->right));
  int balanceFactor = getBalanceFactor(root);
  if (balanceFactor > 1) {
    if (getBalanceFactor(root->left) >= 0) {
      return rightRotate(root);
    } else {
      root->left = leftRotate(root->left);
      return rightRotate(root);
    }
  }
  if (balanceFactor < -1) {
    if (getBalanceFactor(root->right) <= 0) {
      return leftRotate(root);
    } else {
      root->right = rightRotate(root->right);
      return leftRotate(root);
    }
  }
  return root;
}

// Print the tree
void printTree(Node *root, string indent, bool last) {
  if (root != nullptr) {
    cout << indent;
    if (last) {
      cout << "R----";
      indent += "   ";
    } else {
      cout << "L----";
      indent += "|  ";
    }
    cout << root->value << endl;
    printTree(root->left, indent, false);
    printTree(root->right, indent, true);
  }
}

int main() {
  Node *root = NULL;
  root = insertNode(root, 33);
  root = insertNode(root, 13);
  root = insertNode(root, 53);
  root = insertNode(root, 9);
  root = insertNode(root, 21);
  root = insertNode(root, 61);
  root = insertNode(root, 8);
  root = insertNode(root, 11);
  printTree(root, "", true);
  root = deleteNode(root, 13);
  cout << "After deleting " << endl;
  printTree(root, "", true);
}