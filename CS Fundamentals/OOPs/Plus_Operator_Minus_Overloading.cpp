#include <bits/stdc++.h>
using namespace std;

class Marks{
    public:
        int intmark;
        int extmark;

        Marks(){
            intmark=0;
            extmark=0;
        } 

        Marks(int im,int em){
            intmark=im;
            extmark=em;
        }

        void display(){
            cout<<"Internal Marks: "<<intmark<<"\n";
            cout<<"External Marks: "<<extmark<<"\n";
        }

        Marks operator+(Marks m){
            Marks temp;
            temp.intmark=intmark+m.intmark;
            temp.extmark=extmark+m.extmark;
            return temp;
        }

        Marks operator-(Marks m);

};

Marks Marks :: operator-(Marks m){
    Marks temp;
    temp.intmark=intmark-m.intmark;
    temp.extmark=extmark-m.extmark;
    return temp;
}
int main(){
    Marks m1(20,50),m2(30,60);
    Marks m3=m1+m2;
    Marks m4=m1-m2;
    m3.display();
    m4.display();
    return 0;
}