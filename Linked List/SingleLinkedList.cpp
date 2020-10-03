#include <bits/stdc++.h>
using namespace std;
class Node {
  public:
    int key;
    int data;
    Node * next;

  Node() {
    key = 0;
    data = 0;
    next = NULL;
  }
  Node(int k, int d) {
    key = k;
    data = d;
  }
};

class SinglyLinkedList {
  public:
    Node * head;

  SinglyLinkedList() {
    head = NULL;
  }
  SinglyLinkedList(Node * n) {
    head = n;
  }

  //  Check if node exists using key value
  Node * nodeExists(int k) {
    Node * temp = NULL;

    Node * ptr = head;
    while (ptr != NULL) {
      if (ptr -> key == k) {
        temp = ptr;
      }
      ptr = ptr -> next;

    }
    return temp;
  }

  //  Append a node to the list
  void appendNode(Node * n) {
    if (nodeExists(n -> key) != NULL) {
      cout << "Node Already exists with the specified key" << endl;
    } else {
      if (head == NULL) {
        head = n;
        cout << "Node Appended Successfully" << endl;
      } else {
        Node * ptr = head;
        while (ptr -> next != NULL) {
          ptr = ptr -> next;
        }
        ptr -> next = n;
        cout << "Node Appended Successfully" << endl;
      }
    }

  }
  //  Prepend Node 
  void prependNode(Node * n) {
    if (nodeExists(n -> key) != NULL) {
      cout << "Node Already exists with the specified key" << endl;
    } else {
      n -> next = head;
      head = n;
      cout << "Node Prepended" << endl;
    }
  }

  // Insert a Node after a particular node in the list
  void insertNodeAfter(int k, Node * n) {
    Node * ptr = nodeExists(k);
    if (ptr == NULL) {
      cout << "No node exists with the specified key"<<endl;
    } else {
      if (nodeExists(n -> key) != NULL) {
        cout << "Node Already exists with the specified key" << endl;
      } else {
        n -> next = ptr -> next;
        ptr -> next = n;
        cout << "Node Inserted Successfully" << endl;
      }
    }
  }

  // Delete node by key value
  void deleteNodeByKey(int k) {
    if (head == NULL) {
      cout << "Singly Linked List is Empty" << endl;
    } else if (head != NULL) {
      if (head -> key == k) {
        head = head -> next;
        cout << "Node Unlinked with successfully" << endl;
      } else {
        Node * temp = NULL;
        Node * prevptr = head;
        Node * currentptr = head -> next;
        while (currentptr != NULL) {
          if (currentptr -> key == k) {
            temp = currentptr;
            currentptr = NULL;
          } else {
            prevptr = prevptr -> next;
            currentptr = currentptr -> next;
          }
        }
        if (temp != NULL) {
          prevptr -> next = temp -> next;
          cout << "Node Unlinked with successfully" << endl;
        } else {
          cout << "No node exists with the specified key"<< endl;
        }
      }
    }

  }
  // update node
  void updateNodeByKey(int k, int d) {

    Node * ptr = nodeExists(k);
    if (ptr != NULL) {
      ptr -> data = d;
      cout << "Node Data Updated Successfully" << endl;
    } else {
      cout << "No node exists with the specified key"<< endl;
    }

  }

  //Printing the list
  void printList() {
    if (head == NULL) {
      cout << "No Nodes in Singly Linked List";
    } else {
      Node * temp = head;

      while (temp != NULL) {
        cout << "(" << temp -> key << "," << temp -> data << ") --> ";
        temp = temp -> next;
      }
    }

  }

};

int main(){
    SinglyLinkedList s;
  int option;
  int key1, key2, data1;
  while (option != 7) {
    cout << "\nWhat operation do you want to perform? Select Option number" << endl;
    cout << "1. appendNode()" << endl;
    cout << "2. prependNode()" << endl;
    cout << "3. insertNodeAfter()" << endl;
    cout << "4. deleteNodeByKey()" << endl;
    cout << "5. updateNodeByKey()" << endl;
    cout << "6. print()" << endl;
    cout << "7. Exit" << endl << endl;

    cin >> option;
    Node * n1 = new Node(); // storing in heap memory

    switch (option) {
    case 1:
      cout << "Append Node Operation" << endl;
      cout<<"Enter key value: "<<endl;
      cin >> key1;
      cout<<"Enter data value: "<<endl;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      s.appendNode(n1);
      break;

    case 2:
      cout << "Prepend Node Operation" << endl;
      cout<<"Enter key value: "<<endl;
      cin >> key1;
       cout<<"Enter data value: "<<endl;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      s.prependNode(n1);
      break;

    case 3:
      cout << "Insert Node After Operation" << endl;
      cout<<"Enter key value of the node after which you want to insert new Node: "<<endl;
      cin >> key2;
      cout<<"Enter key value of new Node: "<<endl;
      cin >> key1;
      cout<<"Enter data value of new Node: "<<endl;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      s.insertNodeAfter(key2, n1);
      break;

    case 4:

      cout << "Delete Node By Key Operation " << endl;
      cout<<"Enter key value: "<<endl;
      cin >> key1;
      s.deleteNodeByKey(key1);

      break;
    case 5:
      cout << "Update Node By Key Operation" << endl;
      cout<<"Enter key value: "<<endl;
      cin >> key1;
      cout<<"Enter data value: "<<endl;
      cin >> data1;
      s.updateNodeByKey(key1, data1);

      break;
    case 6:
      s.printList();
      break;
    case 7:
    cout<<"Thank You for using our program:)"<<endl;
      break;
    default:
      cout << "Invalid Option number" << endl;
    }
  }
    
    return 0;
}