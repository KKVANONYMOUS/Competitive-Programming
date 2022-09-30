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

        void operator+=(int bonusMarks){
            intmark+=bonusMarks;
        }

        friend void operator-=(Marks &m,int redMarks);

};

void operator-=(Marks &m,int redMarks){
    m.intmark-=redMarks;
}
int main(){
    Marks m1(20);
    m1+=50;
    m1.display();
    m1-=30;
    m1.display();
    return 0;
}