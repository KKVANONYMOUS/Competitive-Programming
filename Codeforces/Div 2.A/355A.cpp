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
    ll k,d;
    cin>>k>>d;
    if (d==0){
        if (k==1){
            cout<<0;
        }
        else{
            cout<<"No solution";
        }
    }
    else {
        string ans=to_string(d);
        fl(i,0,k-1){
            ans+='0';
        }
        cout<<ans;
    }
    return 0;
}