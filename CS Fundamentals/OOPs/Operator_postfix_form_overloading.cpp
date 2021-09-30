#include <bits/stdc++.h>
using namespace std;

class Marks{
    public:
        int intmark;

        Marks(){
            intmark=0;
        } 

        Marks(int im){
            intmark=im;
        }

        void display(){
            cout<<"Internal Marks: "<<intmark<<"\n";
        }

        Marks operator++(int){
            Marks copy(*this);
            intmark++;
            return copy;
        }

        friend Marks operator--(Marks &m,int);

};

Marks operator--(Marks &m,int){
    Marks copy(m);
    m.intmark--;
    return copy;
}

int main(){
    Marks m1(20);
    (m1++).display();
    m1.display();
    (m1--).display();
    m1.display();
    return 0;
}