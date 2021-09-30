#include <bits/stdc++.h>
using namespace std;


class BaseClass{
    public:
          virtual void display(){
            cout<<"Called BaseClass display function\n";
        }
};

class DerivedClass:public BaseClass{
    public:
        void display(){
            cout<<"Called DerivedClass display function\n";
        }
};

int main(){
    //BaseClass *baseclass_obj_pointer;
    //DerivedClass derivedclass_obj;
    //baseclass_obj_pointer=&derivedclass_obj;
    //baseclass_obj_pointer->display();
    BaseClass *obj=new DerivedClass();
    obj->display();
    return 0;
}