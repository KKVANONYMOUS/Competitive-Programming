#include <bits/stdc++.h>
using namespace std;

class Stack
{
private:
    int pos = -1;
    int arr[5] = {0, 0, 0, 0, 0};

public:
    bool isEmpty()
    {
        if (pos == -1)
            return true;
        return false;
    }

    bool isFull()
    {
        if (pos == 4)
            return true;
        return false;
    }

    void push(int val)
    {
        if (isFull())
        {
            cout << "Stack Full\n";
            return;
        }
        arr[++pos] = val;
        cout << "Element added successfully\n";
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Empty\n";
            return;
        }
        arr[pos--] = 0;
        cout << "Element removed successfully\n";
    }

    int peek(int key)
    {
        if (isEmpty())
        {
            cout << "Stack Empty\n";
            return 0;
        }
        return arr[key];
        cout << "Element at " << key << " is " << arr[key] << "\n";
    }

    int count()
    {
        return pos + 1;
    }

    void change(int key, int val)
    {
        if (isEmpty())
        {
            cout << "Stack Empty\n";
            return;
        }
        arr[key] = val;
        cout << "Value at " << key << " changed successfully\n";
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
    Stack obj;
    int option, value, key;
    do
    {
        cout << "What operation do you want to perform? Select Option number. Enter 0 to exit."
             << "\n";
        cout << "1. Push()"
             << "\n";
        cout << "2. Pop()"
             << "\n";
        cout << "3. isEmpty()"
             << "\n";
        cout << "4. isFull()"
             << "\n";
        cout << "5. peek()"
             << "\n";
        cout << "6. count()"
             << "\n";
        cout << "7. change()"
             << "\n";
        cout << "8. display()"
             << "\n";
        cout << "9. Clear Screen"
             << "\n";
        cin >> option;
        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "Enter an item to push in the stack"
                 << "\n";
            cin >> value;
            obj.push(value);
            break;
        case 2:
            obj.pop();
            cout << "Pop Function Called\n";
            break;
        case 3:
            if (obj.isEmpty())
                cout << "Stack is Empty"
                     << "\n";
            else
                cout << "Stack is not Empty"
                     << "\n";
            break;
        case 4:
            if (obj.isFull())
                cout << "Stack is Full"
                     << "\n";
            else
                cout << "Stack is not Full"
                     << "\n";
            break;
        case 5:
            cout << "Enter position of item you want to peek: "
                 << "\n";
            cin >> key;
            cout << "Peek Function Called - Value at key " << key << " is " << obj.peek(key) << "\n";
            break;
        case 6:
            cout << "Count Function Called - Number of Items in the Stack are: " << obj.count() << "\n";
            break;
        case 7:
            cout << "Change Function Called - "
                 << "\n";
            cout << "Enter key of item you want to change : ";
            cin >> key;
            cout << "\n";
            cout << "Enter value of item you want to change : ";
            cin >> value;
            obj.change(key, value);
            break;
        case 8:
            cout << "Display Function Called - "
                 << "\n";
            obj.display();
            break;
        case 9:
            system("cls");
            break;
        default:
            cout << "Enter Proper Option number "
                 << "\n";
        }

    } while (option != 0);
    return 0;
}