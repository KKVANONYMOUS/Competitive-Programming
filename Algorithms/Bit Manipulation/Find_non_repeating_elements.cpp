#include <bits/stdc++.h>
using namespace std;


void print2NonRepeatingNos(vector <int> a,int  n){
    int xoredSum=0;
    for(int i=0;i<n;i++){
        xoredSum=xoredSum^a[i];
    }

    int set_bit_no=xoredSum & ~(xoredSum-1);

    int x=0,y=0;
    for(int i=0;i<n;i++){
        if(a[i] & set_bit_no) x=x^a[i];
        else y=y^a[i];
    }

    cout<<x<<" "<<y;
}
int main(){
    vector <int> a={2, 3, 7, 9, 11, 2, 3, 11}; 
    print2NonRepeatingNos(a,a.size());
    return 0;
}