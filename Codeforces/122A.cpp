#include <bits/stdc++.h>
using namespace std;

#define ll          long long int
#define fl(i,a,n)   for(int i=a;i<n;i++)

void kkvanonymous(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
int main(){
    kkvanonymous();
    int n;
    cin>>n;
    if (n%4==0 || n%7==0 || n%47==0 || n%74==0 || n%447==0 || n%477==0 || n%474==0 || n%774==0 || n%747==0 || n%744==0){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}