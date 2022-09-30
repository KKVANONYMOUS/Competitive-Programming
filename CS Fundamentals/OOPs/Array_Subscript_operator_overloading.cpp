#include <bits/stdc++.h>
using namespace std;


class Marks{
public:
    int subjects[3];
    Marks(int x,int y,int z){
        subjects[0]=x;
        subjects[1]=y;
        subjects[2]=z;
    }

    //we cannot use static or friend function to overload the [] operator 
    int operator[](int key){
        return subjects[key];
    }
};
int main(){
    Marks obj(20,30,50);
    cout<<obj[2];
    return 0;
}