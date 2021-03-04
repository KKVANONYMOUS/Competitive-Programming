#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int value;
	Node *left;
	Node *right;

	Node()
	{
		value = 0;
		left = NULL;
		right = NULL;
	}

	Node(int v)
	{
		value = v;
		left = NULL;
		right = NULL;
	}
};

class AVL
{
public:
	Node *root;

	AVL()
	{
		root = NULL;
	}

	//TO GET HEIGHT
	int getHeight(Node *n)
	{
		if (n == NULL)
			return -1;
		return 1 + max(getHeight(n->left), getHeight(n->right));
	}

	//TO CALCULATE BALANCE FACTOR
	int getBalanceFactor(Node *n)
	{
		if (n == NULL)
			return -1;
		return (getHeight(n->left) - getHeight(n->right));
	}

	//TO ROTATE TREE IN LEFT SENSE
	Node *rotateLeft(Node *n)
	{
		Node *x = n->right;
		Node *T = x->left;

		x->left = n;
		n->right = T;
		return x;
	}

	//TO ROTATE TREE IN RIGHT SENSE
	Node *rotateRight(Node *n)
	{
		Node *x = n->left;
		Node *T = x->right;

		x->right = n;
		n->left = T;
		return x;
	}

	//TO FIND THE MIN NODE IN THE SUB TREE
	Node *maxNode(Node *r){
		if(r==NULL) return r;
		return (r->left);
	}

    //TO INSERT NEW NODE
	Node *insert(Node *r, Node *new_node)
	{
		if (r == NULL)
		{
			r = new_node;
			cout<<"Node inserted successfully";
			return r;
		}
		if (new_node->value < r->value)
		{
			r->left = insert(r->left, new_node);
		}
		else if (new_node->value > r->value)
		{
			r->right = insert(r->right, new_node);
		}
		else
		{
			cout << "Duplicate nodes are not allowed";
			return r;
		}
		int bf = getBalanceFactor(r);

		//LEFT-LEFT
		if (bf > 1 and new_node->value < r->left->value)
		{
			return rotateRight(r);
		}
		//LEFT-RIGHT
		if (bf > 1 and new_node->value > r->left->value)
		{
			r->left = rotateLeft(r->left);
			return rotateRight(r);
		}
		//RIGHT-RIGHT
		if (bf < -1 and new_node->value > r->right->value)
		{
			return rotateLeft(r);
		}
		//RIGHT-LEFT
		if (bf < -1 and new_node->value < r->right->value)
		{
			r->right = rotateRight(r->right);
			return rotateLeft(r);
		}
		return r;
	}

	//TO DELETE NODE FROM AVL TREE
	Node *deleteNode(Node *r,int val){
		if(r==NULL) return r;

		if(val < r->value){
			r->left=deleteNode(r->left,val);
		}
		else if(val > r->value){
			r->right=deleteNode(r->right,val);
		}
		else{
			if(r->left == NULL){
				Node *temp=r->right;
				delete r;
				return temp;
			}
			else if(r->right == NULL){
				Node *temp=r->left;
				delete r;
				return temp;
			}
			else{
				Node *temp=maxNode(r);
				r->value=temp->value;
				r->left=deleteNode(r->left,temp->value);
			}
		}

		int bf=getBalanceFactor(r);
		if(bf==2 and getBalanceFactor(r->left)>=0){
			return rotateRight(r);
		}
		if(bf==2 and getBalanceFactor(r->left)==-1){
			r->left=rotateLeft(r->left);
			return rotateRight(r);
		}
		if(bf==-2 and getBalanceFactor(r->right)<=0){
			return rotateLeft(r);
		}
		if(bf==-2 and getBalanceFactor(r->right)==1){
			r->right=rotateRight(r->right);
			return rotateLeft(r);
		}

		return r;
	}

	//TO SEARCH FOR A GIVEN NODE VALUE
	Node *search(Node *r,int val){
		if(r==NULL or r->value==val) return r;
		else if(val <r->value){
			return search(r->left,val);
		}
		else{
			return search(r->right,val);
		}
	}
	//TO PRINT TREE IN 2D FORM
	void print2D(Node *r, int space)
	{
		if (r == NULL)
			return;
		space += 10;			  
		print2D(r->right, space); 
		cout << endl;
		for (int i = 10; i < space; i++) 
			cout << " ";					
		cout << r->value << "\n";
		print2D(r->left, space);			
	}

	//PREORDER PRINTING
	void preorder(Node *r){
		if(r==NULL) return;

		cout<<r->value<<" ";
		preorder(r->left);
		preorder(r->right);
	}

	//INORDER PRINTING
	void inorder(Node *r){
		if(r==NULL) return;
		
		inorder(r->left);
		cout<<r->value<<" ";
		inorder(r->right);
	}

	//POSTORDER PRINTING
	void postorder(Node *r){
		if(r==NULL) return;
		
		postorder(r->left);
		postorder(r->right);
		cout<<r->value<<" ";
	}

	//UTILITY FUNCTION FOR PRINTING LEVEL ORDER BFS
	void printCurrLevel(Node *r,int l){
		if(r==NULL) return;
		else if (l==0) cout<<r->value<<" ";
		else{
			printCurrLevel(r->left,l-1);
			printCurrLevel(r->right,l-1);
		}
	}
	
	//TO PRINT LEVEL ORDER BFS
	void LevelOrderBFS(Node *root){
		int h=getHeight(root);
		for(int i=0;i<=h;i++){
			cout<<"LEVEL"<<i<<": ";
			printCurrLevel(root,i);
			cout<<endl;
		}
	}
};

int main()
{
	AVL obj; // AVL TREE OBJECT
	int option, value;

	do
	{
		cout << "What operation do you want to perform? "
			 << " Select Option number. Enter 0 to exit." << endl;
		cout << "1. Insert Node" << endl;
		cout << "2. Search Node" << endl;
		cout << "3. Delete Node" << endl;
		cout << "4. Print/Traversal AVL Tree values" << endl;
		cout << "5. Height of Tree" << endl;
		cout << "6. Clear Screen" << endl;
		cout << "0. Exit Program" << endl;

		cin >> option;
		
		Node *new_node = new Node(); //NEW_NODE OBJ MADE IN HEAP MEMORY TO BE USED DURING THE EXECUTION OF THE PROGRAM

		switch (option)
		{
		case 0:
			break;
		case 1:
			cout << "AVL INSERT" << endl;
			cout << "Enter VALUE of TREE NODE to INSERT in AVL Tree: ";
			cin >> value;
			new_node->value = value;
			obj.root = obj.insert(obj.root, new_node);
			cout << endl;
			break;
		case 2:
			cout << "SEARCH" << endl;
			cout << "Enter VALUE of TREE NODE to SEARCH in AVL Tree: ";
			  cin >> value;
			  new_node = obj.search(obj.root, value);
			  if (new_node != NULL) {
			    cout << "Value found" << endl;
			  } else {
			    cout << "Value NOT found" << endl;
			  }
			break;
		case 3:
			cout << "DELETE" << endl;
			cout << "Enter VALUE of TREE NODE to DELETE in AVL: ";
			cin >> value;
			  new_node = obj.search(obj.root, value);
			  if (new_node != NULL) {
			    obj.root = obj.deleteNode(obj.root, value);
			    cout << "Value Deleted" << endl;
			  } else {
			    cout << "Value NOT found" << endl;
			  }
			break;
		case 4:
			cout << "PRINT 2D: " << endl;
			obj.print2D(obj.root, 5);
			cout << endl;
			cout <<"Print Level Order BFS: \n";
			obj.LevelOrderBFS(obj.root);
			cout <<endl;
			cout <<"PRE-ORDER: ";
			obj.preorder(obj.root);
			cout<<endl;
			cout <<"IN-ORDER: ";
			obj.inorder(obj.root);
			cout<<endl;
			cout <<"POST-ORDER: ";
			obj.postorder(obj.root);
			break;
		case 5:
			cout << "TREE HEIGHT" << endl;
			cout << "Height : " << obj.getHeight(obj.root) << endl;
			break;
		case 6:
			system("cls");
			break;
		default:
			cout << "Enter Proper Option number " << endl;
		}

	} while (option != 0);
	return 0;
}
