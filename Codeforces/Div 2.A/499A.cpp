#include <bits/stdc++.h>
using namespace std;

#define ll          long long
#define fl(i,a,n)   for(int i=a;i<n;i++)
#define vi          vector<int>
#define vll         vector<ll>
#define pb          push_back
#define mod         1000000007

void kkvanonymous(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

int main(){
    kkvanonymous();
    ll n,x,s=1,m=0;
    int a[51][2];
    cin>>n>>x;
    fl(i,0,n){
       fl(j,0,2){
           cin>>a[i][j];
       }
    }
    fl(i,0,n){
        s+=((a[i][0]-s)/x)*x;
        m+=a[i][1]-s+1;
        s=a[i][1]+1;
    }
    cout<<m;
    return 0;
}