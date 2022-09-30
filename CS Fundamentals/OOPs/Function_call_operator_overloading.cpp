#include <bits/stdc++.h>
using namespace std;


class Marks{
public:
    int m;
    Marks(int x){
        cout<<"Constructor called\n";
        m=x;
    }

    void display(){
        cout<<"Marks "<<m<<"\n";
    }
    //we cannot use static or friend function to overload the () operator 
    Marks operator()(int mk){
        m=mk;
        return *this;
    }
};
int main(){
    Marks obj(30);
    obj.display();
    obj(50);
    obj.display();
    return 0;
}