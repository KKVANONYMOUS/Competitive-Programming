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
    int n,k,l,c,d,p,nl,np,x=0,soda,lemon,salt,ans;
    cin>>n>>k>>l>>c>>d>>p>>nl>>np;
    soda=(k*l)/nl;
    lemon=c*d;
    salt=p/np;
    ans=min(soda,lemon);
    cout<<min(ans,salt)/n;
    return 0;
}
