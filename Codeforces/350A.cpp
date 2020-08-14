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
    int n,m,x;
    cin>>n>>m;
    vi c;
    vi in;
    fl(i,0,n){
        cin>>x;
        c.pb(x);
    }
    fl(i,0,m){
        cin>>x;
        in.pb(x);
    }
    sort(c.begin(),c.end());
    sort(in.begin(),in.end());
    if(max((2*c[0]),(c[c.size()-1]))<in[0]){
        cout<<max((2*c[0]),(c[c.size()-1]));
    }
    else{
        cout<<-1;
    }
    return 0;
}