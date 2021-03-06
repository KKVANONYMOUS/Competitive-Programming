#include <iostream>
using namespace std;

class TreeNode
{
public:
  int value;
  TreeNode *left;
  TreeNode *right;

  TreeNode()
  {
    value = 0;
    left = NULL;
    right = NULL;
  }

  TreeNode(int v)
  {
    value = v;
    left = NULL;
    right = NULL;
  }
};

class BST
{
public:
  TreeNode *root;

  BST()
  {
    root = NULL;
  }

  bool isTreeEmpty()
  {
    if (root == NULL)
      return true;
    return false;
  }

  //TO INSERT NEW NODE
  void insertNode(TreeNode *new_node)
  {
    if (root == NULL)
    {
      root = new_node;
      cout << "Node inserted as root node" << endl;
    }
    else
    {
      TreeNode *temp = root;
      while (temp != NULL)
      {
        if (temp->value == new_node->value)
        {
          cout << "Node exists with the same value\n"
               << "Insert another value!" << endl;
          return;
        }
        else if ((temp->value > new_node->value) && (temp->left == NULL))
        {
          temp->left = new_node;
          cout << "Node inserted to left" << endl;
          break;
        }
        else if (temp->value > new_node->value)
        {
          temp = temp->left;
        }
        else if ((temp->value < new_node->value) && (temp->right == NULL))
        {
          temp->right = new_node;
          cout << "Node inserted to right" << endl;
          break;
        }
        else
        {
          temp = temp->right;
        }
      }
    }
  }

  //TO SEARCH FOR THE GIVEN KEY
  TreeNode *IterativeSearch(int val){
    if (root==NULL) return root;
    TreeNode *temp=root;
    while (temp!=NULL){
      if (temp->value==val) return temp;
      else if (val<temp->value) temp=temp->left;
      else temp=temp->right;
    }
    return NULL;
  }

  //TO FIND HEIGHT OF BST
  int findHeight(TreeNode *r){
    if (r==NULL) return -1;
    else {
      int lHeight=findHeight(r->left);
      int rHeight=findHeight(r->right);
      if (rHeight>lHeight) return rHeight+1;
      else return lHeight+1;
    }
  }

  //UTILITY FUNCTION FOR DELETENODE
  TreeNode *minValueNode(TreeNode *r){
    if (r==NULL) return r;
    else if (r->left!=NULL){
      TreeNode *temp=minValueNode(r->left);
      return temp;
    }
    return r;
  }

  //TO DELETE NODE
  TreeNode *deleteNode(TreeNode *r,int val){
    if (r==NULL) return r; //Base condition
    else if (val<r->value) r->left=deleteNode(r->left,val); // if value smaller go left sub tree
    else if(val>r->value) r->right=deleteNode(r->right,val); // if value greater go right sub tree
    else{ // value matches
      if (r->left==NULL){ //node with only right child or no child
        TreeNode *temp = r->right;
        delete r; 
        return temp;
      }
      else if (r->right==NULL){ // node with only left child
        TreeNode *temp = r->left; 
        delete r;
        return temp;
      }
      else{ // node with two children
        TreeNode *temp=minValueNode(r->right);
        r->value=temp->value;
        r->right=deleteNode(r->right,temp->value);
      }
    }
    return r;
  }

  //DFS-PreOrder Tree Traversal (NLR)
  void printPreOrder(TreeNode *r){
    if (r==NULL) return;
    cout<<r->value<<" ";
    printPreOrder(r->left);
    printPreOrder(r->right);
  }

  //DFS-InOrder Tree Traversal (LNR)
  void printInOrder(TreeNode *r){
    if (r==NULL) return;
    printPreOrder(r->left);
    cout<<r->value<<" ";
    printPreOrder(r->right);
  }

  //DFS-PostOrder Tree Traversal (LRN)
  void printPostOrder(TreeNode *r){
    if (r==NULL) return;
    printPreOrder(r->left);
    printPreOrder(r->right);
    cout<<r->value<<" ";
  }

  //TO PRINT TREE USING BFS
  void printTreeByBFS(){
    int h=findHeight(root);
    for(int i=0;i<=h;i++){
      cout<<"Level "<<i<<": ";
      printCurrentLevel(root,i);
      cout<<"\n";
    }
  }

  //TO PRINT CURRENT LEVEL (utility function for printing tree using BFS)
  void printCurrentLevel(TreeNode *r,int level){
    if (r==NULL) return;
    else if (level==0) cout<<r->value<<" ";
    else {
      printCurrentLevel(r->left,level-1);
      printCurrentLevel(r->right,level-1);
    }
  }

  //PRINT tree in graphical way
  void Print2D(TreeNode *r,int space){
    if (r==NULL) return;
    space+=5;
    Print2D(r->right,space);
    cout<<"\n";
    for(int i=5;i<space;i++) cout<<" ";
    cout<<r->value<<"\n";
    Print2D(r->left,space);
  }

};

int main()
{
  int option, value;
  BST obj;
  do
  {
    cout << "What operation do you want to perform? "
         << " Select Option number. Enter 0 to exit." << endl;
    cout << "1. Insert Node" << endl;
    cout << "2. Search Node" << endl;
    cout << "3. Delete Node" << endl;
    cout << "4. Print/Traversal BST values" << endl;
    cout << "5. Height of Tree" << endl;
    cout << "6. Print Tree using BFS" << endl;
    cout << "7. Clear Screen" << endl;
    cout << "0. Exit Program" << endl;

    cin >> option;
    
    TreeNode *new_node = new TreeNode(); 
    /*
     by doing so we are creating the object in the heap memory
     so that it is globally available throughtout the execution of
      the program, otherwise we might have used `TreeNode new_node`,
       but this would have created the obj in stack memory which 
       will not make our obj available globally
    */

    switch (option)
    {
    case 0:
      break;
    case 1:
      cout << "INSERT" << endl;
      cout << "Enter the value to be inserted in BST" << endl;
      cin >> value;
      new_node->value = value;
      obj.insertNode(new_node);
      break;
    case 2:
      cout << "SEARCH" << endl;
      cout<<"Enter the value to be searched in BST"<<endl;
      cin>>value;
      if(obj.IterativeSearch(value)==NULL){
        cout<<"Value NOT present in the BST"<<endl;
      }
      else{
        cout<<"Value found"<<endl;
      }
      break;
    case 3:
      cout << "DELETE" << endl;
      cout<<"Enter the value to be deleted"<<endl;
      cin>>value;
      new_node=obj.IterativeSearch(value);
      if(new_node!=NULL){
        obj.deleteNode(obj.root,value);
        cout<<"Node deleted successfully"<<endl;
      }
      else{
        cout<<"Value NOT present in the BST"<<endl;
      }
      break;
    case 4:
      cout << "PRINT2D" << endl;
      //obj.printPreOrder(obj.root);
      //obj.printInOrder(obj.root);
      //obj.printPostOrder(obj.root);
      obj.Print2D(obj.root,5);
      cout<<"\n";
      break;
    case 5:
      cout << "TREE HEIGHT" << endl;
      cout<<"Height of BST is: "<<obj.findHeight(obj.root)<<endl;
      break;
    case 6:
      cout<<"PRINT BFS"<<endl;
      obj.printTreeByBFS();
      break;
    case 7:
      system("cls");
      break;
    default:
      cout << "Enter valid Option number " << endl;
    }
  } while (option != 0);

  return 0;
}