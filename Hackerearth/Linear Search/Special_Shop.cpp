#include <bits/stdc++.h>
using namespace std;

#define ll          long long
#define fl(i,a,n)   for(int i=a;i<n;i++)
#define all(c)      c.begin(), c.end()
#define vi          vector<int>
#define vll         vector<ll>
#define pii         pair<int,int>
#define pb          push_back
#define mp          make_pair
#define f           first
#define s           second
#define mod         1000000007

void kkvanonymous(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

void solve(){
    ll n,a,b;
    cin>>n>>a>>b;
    ll y=n*b/(a+b);
    ll case1=a*pow(y,2)+b*pow((n-y),2);
    ll case2=a*pow(y+1,2)+b*pow((n-y-1),2);
    cout<<min(case1,case2)<<"\n";
}
int main(){
    kkvanonymous();
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}