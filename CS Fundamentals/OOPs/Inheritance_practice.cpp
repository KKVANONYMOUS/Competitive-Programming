#include <bits/stdc++.h>
using namespace std;


class Person{
    public:
        string name;
    public:
        void setName(string iname) {
            name=iname;
        }
};

class Student : private Person{
    public:
        void display(){
            cout<<name;
        }

        void setStudentName(string iname){
            setName(iname);
        }
};

class GStudent:private Student{
    public:
        void setStudentNameG(string iname){
            setStudentName(iname);
        }
        void displayG(){
            display();
        }
};

int main(){
    GStudent anil;
    anil.setStudentNameG("anil");
    //anil.setStudentName("anil");
    anil.displayG();
    return 0;
}