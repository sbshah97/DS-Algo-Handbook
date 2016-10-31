#include <iostream> 
#include <algorithm> // std::max

struct Node {
  int data;
  Node* left;
  Node* right;
};

class Tree {
public:
  Tree() : root_(nullptr) { }

  int GetHeight(Node* root);
  int Diff(Node* root);
  Node* RightRight_Rotation(Node* root);
  Node* LeftLeft_Rotation(Node* root);
  Node* LeftRight_Rotation(Node* root);
  Node* RightLeft_Rotation(Node* root);
  Node* Balance(Node* root);
  Node* Insert(Node* root, int value);
  void Display(Node* root, int level);
  void Inorder(Node* root);
  void Preorder(Node* root);
  void Postorder(Node* root);

  Node* root() { return this->root_; }

private:
 Node* root_;
};


int Tree::GetHeight(Node *temp) {
  int h = 0;
  if (temp) {
    int l_GetHeight = GetHeight(temp->left);
    int r_GetHeight = GetHeight(temp->right);
    int max_GetHeight = std::max(l_GetHeight, r_GetHeight);
    h = max_GetHeight + 1;
  }

  return h;
}


int Tree::Diff(Node* temp) {
  int l_GetHeight = GetHeight(temp->left);
  int r_GetHeight = GetHeight(temp->right);
  int b_factor = (l_GetHeight - r_GetHeight);
  return b_factor;
}

Node* Tree::RightRight_Rotation(Node* parent) {
  Node* temp;
  temp = parent->right;
  parent->right = temp->left;
  temp->left = parent;
  return temp;
}

Node* Tree::LeftLeft_Rotation(Node* parent) {
  Node* temp;
  temp = parent->left;
  parent->left = temp->right;
  temp->right = parent;
  return temp;
}

Node* Tree::LeftRight_Rotation(Node* parent) {
  Node* temp = parent->left;
  parent->left = RightRight_Rotation(temp);
  return LeftLeft_Rotation(parent);
}

Node* Tree::RightLeft_Rotation(Node* parent) {
  Node* temp = parent->right;
  parent->right = LeftLeft_Rotation(temp);
  return RightRight_Rotation(parent);
}

Node* Tree::Balance(Node* temp) {
  int balanceFactor = Diff(temp);
  
  if (balanceFactor > 1) {
    if (Diff (temp->left) > 0) {
      temp = LeftLeft_Rotation(temp);
    } else {
      temp = LeftRight_Rotation(temp);
    }
  } else if (balanceFactor < -1) {
    if (Diff(temp->right) > 0) {
      temp = RightLeft_Rotation(temp);        
    } else {
      temp = RightRight_Rotation(temp);
    }
  }

  return temp;
}

Node* Tree::Insert(Node* root, int value) {
  if (!root) {
    root = new Node;
    root->data = value;
    root->left = NULL;
    root->right = NULL;
    return root;
  } else if (value < root->data) {
    root->left = Insert(root->left, value);
    root = Balance(root);
  } else if (value >= root->data) {
    root->right = Insert(root->right, value);
    root = Balance(root);
  }

  return root;
}

void Tree::Display(Node* current, int level) {
  if (!current) return;

  Display(current->right, level + 1);
  std::cout << std::endl;
  if (current == root()) {
    std::cout<<"Root -> ";
    for (int i = 0; i < level && current != root(); ++i) {
      std::cout << "           ";
    }
    std::cout << current->data;
    Display(current->left, level+1);
  }
}

void Tree::Inorder(Node* root) {
  if (!root) {
    return;
  }
  
  Inorder(root->left);
  std::cout << root->data<< "      ";
  Inorder(root->right);
}

void Tree::Preorder(Node* root) {
  if (!root) return;

  std::cout << root->data << "  ";
  Preorder(root->left);
  Preorder(root->right);
}

void Tree::Postorder(Node* root) {
  if (!root) return;

  Postorder(root->left);
  Postorder(root->right);
  std::cout<<root->data<<"  ";
}

/**
 *  * Prompts user for input selection using stdin.
 *   */
 int main() {
  int choice = 0, item = 0;
  Tree avl;

  while(1) {
    std::cout << "Enter your choice: " << std::endl;
    std::cout << "1: Insert a value" << std::endl;
    std::cout << "2: Display balanced AVL Tree" << std::endl;
    std::cout << "3: Print Inorder traversal" << std::endl;
    std::cout << "4: Print Preorder traversal" << std::endl;
    std::cout << "5: Print Postorder traversal" << std::endl;
    std::cout << "6: Exit" << std::endl;
    std::cin >> choice;
    switch(choice) {
      case 1:
      std::cout << "Enter value to be Inserted: ";
      std::cin >> item;
      avl.Insert(avl.root(), item);
      break;
      case 2:
      if (!avl.root()) {
        std::cout << "Tree is empty!" << std::endl;
        continue;
      }
      std::cout << "Balanced AVL Tree:" <<std::endl;
      avl.Display(avl.root(), 1);
      break;
      
      case 3:
      std::cout << "Inorder:" << std::endl;
      avl.Inorder(avl.root());
      std::cout << std::endl;
      break;
      
      case 4:
      std::cout << "Preorder: " << std::endl;
      avl.Preorder(avl.root());
      std::cout << std::endl;
      break;
      
      case 5:
      std::cout << "Postorder: " << std::endl;
      avl.Inorder(avl.root());
      std::cout << std::endl;    
      break;
      
      case 6: 
      exit(1);
      break;
      
      default:
      std::cout << "Wrong choice" << std::endl;
    }
  }

  return 0;
}
