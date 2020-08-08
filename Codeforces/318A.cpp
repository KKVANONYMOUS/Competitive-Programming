#include <bits/stdc++.h>
using namespace std;

#define ll          long long
#define fl(i,a,n)   for(int i=a;i<n;i++)

void kkvanonymous(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
int main(){
    kkvanonymous();
    ll k,n;
    cin>>n>>k;
    if (k<=(n+1)/2){//awesome logic
        cout<<2*k-1;
    }
    else{
        cout<<(k-((n+1)/2))*2;
    }
    return 0;
}