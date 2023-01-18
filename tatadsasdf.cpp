// Create a Binary Search Tree and perform the following operations:
// 1. Insert a node
// 2. Delete a node
// 3. Search a node
// 4. Display the tree
// 5. Exit

#include <iostream.h>
#include <conio.h>
#include <process.h>

class BST
{
  struct node
  {
    int data;
    node *left;
    node *right;
  };
  node *root;
  public:
  BST()
  {
    root = NULL;
  }
  void insert();
  void del();
  void search();
  void display(node *);
  void inorder(node *);
  void preorder(node *);
  void postorder(node *);
};

void BST::insert()
{
  node *temp = new node;
  cout << "Enter the data to be inserted: ";
  cin >> temp->data;
  temp->left = NULL;
  temp->right = NULL;
  if(root == NULL)
  {
    root = temp;
  }
  else
  {
    node *current = root;
    node *parent = NULL;
    while(current != NULL)
    {
      parent = current;
      if(temp->data > current->data)
      {
        current = current->right;
      }
      else
      {
        current = current->left;
      }
    }
    if(temp->data > parent->data)
    {
      parent->right = temp;
    }
    else
    {
      parent->left = temp;
    }
  }
}

void BST::del()
{
  int key;
  cout << "Enter the data to be deleted: ";
  cin >> key;
  node *current = root;
  node *parent = NULL;
  while(current != NULL)
  {
    if(current->data == key)
    {
      break;
    }
    else
    {
      parent = current;
      if(key > current->data)
      {
        current = current->right;
      }
      else
      {
        current = current->left;
      }
    }
  }
  if(current == NULL)
  {
    cout << "The data to be deleted is not found in the tree" << endl;
  }
  else
  {
    if(current->left == NULL && current->right == NULL)
    {
      if(parent->left == current)
      {
        parent->left = NULL;
      }
      else
      {
        parent->right = NULL;
      }
      delete current;
    }
    else if(current->left == NULL || current->right == NULL)
    {
      if(current->left == NULL)
      {
        if(parent->left == current)
        {
          parent->left = current->right;
        }
        else
        {
          parent->right = current->right;
        }
      }
      else
      {
        if(parent->left == current)
        {
          parent->left = current->left;
        }
        else
        {
          parent->right = current->left;
        }
      }
      delete current;
    }
    else
    {
      node *temp = current->right;
      node *temp1 = current;
      while(temp->left != NULL)
      {
        temp1 = temp;
        temp = temp->left;
      }
      current->data = temp->data;
      if(temp1->left == temp)
      {
        temp1->left = temp->right;
      }
      else
      {
        temp1->right = temp->right;
      }
      delete temp;
    }
  }
}

void BST::search()
{
  int key;
  cout << "Enter the data to be searched: ";
  cin >> key;
  node *current = root;
  while(current != NULL)
  {
    if(current->data == key)
    {
      cout << "The data is found in the tree" << endl;
      break;
    }
    else
    {
      if(key > current->data)
      {
        current = current->right;
      }
      else
      {
        current = current->left;
      }
    }
  }
  if(current == NULL)
  {
    cout << "The data is not found in the tree" << endl;
  }
}

void BST::display(node *current)
{
  int choice;
  cout << "1. Inorder" << endl;
  cout << "2. Preorder" << endl;
  cout << "3. Postorder" << endl;
  cout << "Enter your choice: ";
  cin >> choice;
  switch(choice)
  {
    case 1:
      inorder(current);
      break;
    case 2:
      preorder(current);
      break;
    case 3:
      postorder(current);
      break;
    default:
      cout << "Invalid choice" << endl;
  }
}

void BST::inorder(node *current)
{
  if(current != NULL)
  {
    inorder(current->left);
    cout << current->data << " ";
    inorder(current->right);
  }
}

void BST::preorder(node *current)
{
  if(current != NULL)
  {
    cout << current->data << " ";
    preorder(current->left);
    preorder(current->right);
  }
}

void BST::postorder(node *current)
{
  if(current != NULL)
  {
    postorder(current->left);
    postorder(current->right);
    cout << current->data << " ";
  }
}

void main()
{
  clrscr();
  BST b;
  int choice;
  while(1)
  {
    cout << "1. Insert" << endl;
    cout << "2. Delete" << endl;
    cout << "3. Search" << endl;
    cout << "4. Display" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch(choice)
    {
      case 1:
        b.insert();
        break;
      case 2:
        b.del();
        break;
      case 3:
        b.search();
        break;
      case 4:
        b.display(b.root);
        break;
      case 5:
        exit(0);
      default:
        cout << "Invalid choice" << endl;
    }
  }
  getch();
}