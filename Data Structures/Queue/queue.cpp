#include <bits/stdc++.h>
using namespace std;

class Queue
{
private:
    int front = -1;
    int rear = -1;
    int arr[5] = {0, 0, 0, 0, 0};

public:
    bool isEmpty()
    {
        if (front == -1 && rear==-1)
            return true;
        return false;
    }

    bool isFull()
    {
        if ((rear-front+1)==5)
            return true;
        return false;
    }

    void enqueue(int val)
    {
        if (isFull())
        {
            cout << "Queue Full\n";
            return;
        }
        if(isEmpty()){
            arr[++front]=val;
            rear++;
        }
        else{
            arr[++rear]=val;
        }
        cout << "Element added successfully\n";
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Empty\n";
            return;
        }
        if(rear==front){
            arr[front]=0;
            rear--;
            front--;
        }
        else{
            arr[front++]=0;
        }
        cout << "Element removed successfully\n";
    }

    int count()
    {
        if(isEmpty()) return 0;
        return rear-front+1;
    }

    void display()
    {
        for (int i = 0; i < 5; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
};
int main()
{
    Queue obj;
    int option, value, key;
    do {
    cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. Enqueue()" << endl;
    cout << "2. Dequeue()" << endl;
    cout << "3. isEmpty()" << endl;
    cout << "4. isFull()" << endl;
    cout << "5. count()" << endl;
    cout << "6. display()" << endl;
    cout << "7. Clear Screen" << endl << endl;
 
    cin >> option;
 
    switch (option) {
    case 0:
      break;
    case 1:
      cout << "Enqueue Operation \nEnter an item to Enqueue in the Queue" << "\n";
      cin >> value;
      obj.enqueue(value);
      break;
    case 2:
      obj.dequeue();
      cout << "Dequeue Operation called\n";
      break;
    case 3:
      if (obj.isEmpty())
        cout << "Queue is Empty" << "\n";
      else
        cout << "Queue is not Empty" << "\n";
      break;
    case 4:
      if (obj.isFull())
        cout << "Queue is Full" << "\n";
      else
        cout << "Queue is not Full" << "\n";
      break;
    case 5:
      cout << "Count Operation \nCount of items in Queue : " << obj.count() << "\n";
      break;
    case 6:
      cout << "Display Function Called - " << "\n";
      obj.display();
      break;
    case 7:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << "\n";
    }
 
  } while (option != 0);
    return 0;
}