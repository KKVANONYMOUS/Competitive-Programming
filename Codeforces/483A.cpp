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
    ll l,r,flag=0;
    vll a;
    cin>>l>>r;
    for(ll i=l;i<=r;i++){
        for(ll j=i+1;j<=r;j++){
            for(ll m=j+1;m<=r;m++){
                if ( __gcd(i,j)==1 && __gcd(j,m)==1 && __gcd(i,m)!=1 && i!=j && j!=m && i!=m){
                    a.pb(i);
                    a.pb(j);
                    a.pb(m);
                    flag=1;
                    break;
                }
            }
            if (flag){
                break;
            }
        
        }
        if(flag){
            break;
        }
    }
    if(flag){
        sort(a.begin(),a.end());
        cout<<a[0]<<" "<<a[1]<<" "<<a[2];
    }
    else{
        cout<<-1;
    }
    
    return 0;
}