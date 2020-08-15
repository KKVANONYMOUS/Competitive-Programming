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
    int n,k,m=0,c=0;
    ll x;
    cin>>n>>k;
    vll a;
    fl(i,0,n){
        cin>>x;
        a.pb(x);
    }
    for(auto i=a.begin();i!=a.end();i++){
        string s=to_string(*i);
        c=0;
        for(ll j=0;j<s.size();j++){
            if (s[j]==52 || s[j]==55){
                c++;
            }
        }
        if(c<=k){
            m++;
        }
    }
    cout<<m;
    return 0;
}