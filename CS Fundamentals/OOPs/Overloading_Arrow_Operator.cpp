#include <bits/stdc++.h>
using namespace std;


class Marks{
    int mark;
public:
    Marks (int m){
        mark=m;
    }

    void display(){
        cout<<"Marks "<<mark<<"\n";
    }

    //we cannot use static or friend function to overload the -> operator 
    Marks* operator->(){
        return this;
    }
};
int main(){
    Marks obj(50);
    obj.display();
    obj->display();
    return 0;
}