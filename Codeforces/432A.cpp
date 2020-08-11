#include <bits/stdc++.h>
using namespace std;

#define ll          long long
#define fl(i,a,n)   for(int i=a;i<n;i++)

void kkvanonymous(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
int main(){
    kkvanonymous();
    int n,k,a[2001],b[2001],c=0;
    cin>>n>>k;
    fl(i,0,n){
        cin>>a[i];
    }
    fl(i,0,n){
        if (a[i]+k<=5){
            b[c]=a[i];
            c++;
        }
    }
    if(c<3){
        cout<<0;
    }
    else {
        cout<<c/3;
    }
    return 0;
}