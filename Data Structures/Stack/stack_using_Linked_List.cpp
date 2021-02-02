#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int key,val;
        Node * next;

    Node(){
        key=0;
        val=0;
        next=NULL;
    }
    Node(int k,int v){
        key=k;
        val=v;
        next=NULL;
    }
};

class StackLL{
    public:
        Node *top;

    StackLL(){
        top=NULL;
    }

    bool isEmpty(){
        if (top==NULL) return true;
        return false;
    }

    bool checkIfNodeexists(Node *n){
        Node * temp=top;
        while(temp!=NULL){
            if(temp->key==n->key) return true;
            temp=temp->next;
        }
        return false;
    }

    void push(Node *n){
        if(top==NULL){
            top=n;
            cout<<"Node pushed successfully\n";
        }
        else if(checkIfNodeexists(n)){
            cout<<"Node already exists with this key value. Enter different key to proceed\n";
        }
        else{
            Node *temp=top;
            top=n;
            n->next=temp;
            cout<<"Node pushed successfully\n";
        }
    }

    Node *pop(){
        if(isEmpty()){
            cout<<"Stack underflow\n";
            return NULL;
        }
        else{
            Node *temp=top;
            top=top->next;
            return temp;
        }
    }

    Node *peek(){
        if(isEmpty()){
            cout<<"Stack underflow\n";
            return NULL;
        }
        else{
            return top;
        }
    }

    int count(){
        if(isEmpty()) return 0;
        else{
            int cnt=0;
            Node *temp=top;
            while(temp!=NULL){
                cnt++;
                temp=temp->next;
            }
            return cnt;
        }
    }

    void display(){
        Node *temp=top;
        while(temp!=NULL){
            cout<<"( "<<temp->key<<","<<temp->val<<" ) -> \n";
            temp=temp->next;
        }
    }
};
int main(){
    StackLL obj;
    int option,key,val;

    do{
        cout << "What operation do you want to perform?" <<
      "Select Option number. Enter 0 to exit." << endl;
    cout << "1. Push()" << endl;
    cout << "2. Pop()" << endl;
    cout << "3. isEmpty()" << endl;
    cout << "4. peek()" << endl;
    cout << "5. count()" << endl;
    cout << "6. display()" << endl;
    cout << "7. Clear Screen" << endl << endl;

    cin >> option;

    Node *n=new Node();

    switch (option) {
    case 0:
      break;
    case 1:
      cout << "Enter KEY and VALUE of NODE to push in the stack" <<
        "\n";
      cin >> key;
      cin >> val;
      n -> key = key;
      n -> val = val;
      obj.push(n);
      break;
    case 2:
      cout << "Pop Function Called - Poped Value: " << "\n";
      n = obj.pop();
      cout << "TOP of Stack is: (" << n -> key << "," << n -> val << ")";
      delete n;
      cout << "\n";
 
      break;
    case 3:
      if (obj.isEmpty())
        cout << "Stack is Empty" << "\n";
      else
        cout << "Stack is not Empty" << "\n";
      break;
    case 4:
      if (obj.isEmpty()) {
        cout << "Stack is Empty" << "\n";
      } else {
        cout << "PEEK Function Called : " << "\n";
        n = obj.peek();
        cout << "TOP of Stack is: (" << n -> key << "," << n -> val << ")" <<
          "\n";
      }
      break;
    case 5:
      cout << "Count Function Called: " << "\n";
      cout << "No of nodes in the Stack: " << obj.count() << "\n";
      break;
 
    case 6:
      cout << "Display Function Called - " << "\n";
      obj.display();
      cout << "\n";
      break;
    case 7:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << "\n";
    }
    }while(option!=0);
    return 0;
}