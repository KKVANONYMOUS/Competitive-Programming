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

int main(){
    kkvanonymous();
    ll n,flag=0,min=8888888888;
    cin>>n;
    for(ll i=n+1;i<=(n+16);i++){
        ll m=i;
        string s=to_string(m);
        for(ll j=0;j<s.size();j++){
            if (s[j]==56){
                flag=1;
                break;
            }
        }
        if (flag && i<min){
            min=i;
        }
    }
    cout<<abs(min-n);
    return 0;
}