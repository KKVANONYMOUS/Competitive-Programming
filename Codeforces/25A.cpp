#include <bits/stdc++.h>
using namespace std;

#define ll          long long
#define fl(i,a,n)   for(int i=a;i<n;i++)

void kkvanonymous(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
int main(){
    kkvanonymous();
    int n,a[101],b=0,c=0,e[101],o[101],output;
    cin>>n;
    fl(i,0,n){
        cin>>a[i];
    }
    fl(i,0,n){
        if(a[i]%2==0){
            e[b]=i+1;
            b++;
        }
        else{
            o[c]=i+1;
            c++;
        }
    }
    output=min(b,c);
    if (output==b){
        cout<<e[0];
    }
    else{
        cout<<o[0];
    }
    return 0;
}