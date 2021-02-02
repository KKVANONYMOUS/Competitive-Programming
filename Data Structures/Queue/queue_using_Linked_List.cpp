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

class QueueLL{
    public:
        Node *front;
        Node *rear;

    QueueLL(){
        front=NULL;
        rear=NULL;
    }

    bool isEmpty(){
        if (front==NULL && rear==NULL) return true;
        return false;
    }

    bool checkIfNodeexists(Node *n){
        Node * temp=front;
        while(temp!=NULL){
            if(temp->key==n->key) return true;
            temp=temp->next;
        }
        return false;
    }

    void enqueue(Node *n){
        if(front==NULL){
            front=n;
            rear=n;
            cout<<"Node pushed successfully\n";
        }
        else if(checkIfNodeexists(n)){
            cout<<"Node already exists with this key value. Enter different key to proceed\n";
        }
        else{
            rear->next=n;
            rear=n;
            cout<<"Node pushed successfully\n";
        }
    }

    Node *dequeue(){
        if(isEmpty()){
            cout<<"Queue underflow\n";
            return NULL;
        }
        else{
            if(front==rear){
                Node *temp=front;
                front=rear=NULL;
                return temp;
            }
            else{
                Node *temp=front;
                front=front->next;
                return temp;
            }
        }
    }

    int count(){
        if(isEmpty()) return 0;
        else{
            int cnt=0;
            Node *temp=front;
            while(temp!=NULL){
                cnt++;
                temp=temp->next;
            }
            return cnt;
        }
    }

    void display(){
        Node *temp=front;
        while(temp!=NULL){
            cout<<"( "<<temp->key<<","<<temp->val<<" ) -> \n";
            temp=temp->next;
        }
    }
};
int main(){
    QueueLL obj;
    int option,key,val;

    do{
        cout << "What operation do you want to perform?"
 <<"Select Option number. Enter 0 to exit." << "\n";
    cout << "1. Enqueue()" << "\n";
    cout << "2. Dequeue()" << "\n";
    cout << "3. isEmpty()" << "\n";
    cout << "4. count()" << "\n";
    cout << "5. display()" << "\n";
    cout << "6. Clear Screen" << "\n" << "\n";
 cin >> option;
 
 Node * n = new Node();
 
    
    switch (option) {
    case 0:
      break;
    case 1:
    	cout << "ENQUEUE Function Called -" <<"\n";
      cout << "Enter KEY and VALUE of NODE to ENQUEUE "
 <<"in the Queue"
 <<"\n";
      cin >> key;
      cin >> val;
      n->key = key;
      n->val = val;
      obj.enqueue(n);
      break;
    case 2:
      cout << "DEQUEUE Function Called - " <<"\n";
      n = obj.dequeue();
      if(n!=NULL){
         cout<<"Dequeued Value is: ("<<n->key<<","
 <<n->val<<")";
      delete n;
      }
      
 cout<<"\n";
      
      break;
    case 3:
    	cout << "isEmpty Function Called - " << "\n";
      if (obj.isEmpty())
        cout << "Queue is Empty" << "\n";
      else
        cout << "Queue is NOT Empty" << "\n";
      break;
    case 4:
    	cout << "Count Function Called - " << "\n";
      cout << "No of nodes in the Queue: " <<obj.count()
 <<"\n";
      break;
    case 5:
      cout << "Display Function Called - " << "\n";
      obj.display();
      cout << "\n";
      break;
    
    case 6:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << "\n";
    }
    }while(option!=0);
    return 0;
}