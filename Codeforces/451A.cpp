#include <bits/stdc++.h>
using namespace std;

#define ll          long long int
#define fl(i,a,n)   for(int i=a;i<n;i++)

void kkvanonymous(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
int main(){
    kkvanonymous();
    int h,v;
    cin>>h>>v;
    int flag=0;
    while(h*v!=0){
        h--;
        v--;
        if (flag==0){
            flag=1;
        }
        else{
            flag=0;
        }
    }
    if (flag==0){
        cout<<"Malvika";
    }
    else{
        cout<<"Akshat";
    }
    return 0;
}