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

        void operator++(){
            intmark++;
        }

        friend void operator--(Marks &m);

};

void operator--(Marks &m){
    m.intmark--;
}
int main(){
    Marks m1(20);
    ++m1;
    m1.display();
    --m1;
    m1.display();
    return 0;
}