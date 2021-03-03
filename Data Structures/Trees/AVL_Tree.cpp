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
			//  cin >> val;
			//  //new_node = obj.iterativeSearch(val);
			//  new_node = obj.recursiveSearch(obj.root, val);
			//  if (new_node != NULL) {
			//    cout << "Value found" << endl;
			//  } else {
			//    cout << "Value NOT found" << endl;
			//  }
			break;
		case 3:
			cout << "DELETE" << endl;
			cout << "Enter VALUE of TREE NODE to DELETE in AVL: ";
			cin >> value;
			//  new_node = obj.recursiveSearch(obj.root, val);
			//  if (new_node != NULL) {
			//    obj.root = obj.deleteNode(obj.root, val);
			//    cout << "Value Deleted" << endl;
			//  } else {
			//    cout << "Value NOT found" << endl;
			//  }
			break;
		case 4:
			cout << "PRINT 2D: " << endl;
			obj.print2D(obj.root, 5);
			cout << endl;
			//cout <<"Print Level Order BFS: \n";
			//obj.printLevelOrderBFS(obj.root);
			//cout <<endl;
			//	      cout <<"PRE-ORDER: ";
			//	      obj.printPreorder(obj.root);
			//	      cout<<endl;
			//	      cout <<"IN-ORDER: ";
			//	      obj.printInorder(obj.root);
			//	      cout<<endl;
			//	      cout <<"POST-ORDER: ";
			//	      obj.printPostorder(obj.root);
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
