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
    int n,x,sumc=0,sumb=0,sumba=0;
    vi a;
    vi c;
    vi b;
    vi ba;
    cin>>n;
    fl(i,0,n){
        cin>>x;
        a.pb(x);
    }
    for(int i=0;i<a.size();i+=3){
        if (a[i] ){
            c.pb(a[i]);
        }
        if (a[i+1] && (i+1)<a.size()){
            b.pb(a[i+1]);
        }
        if (a[i+2] && (i+2)<a.size()){
            ba.pb(a[i+2]);
        }        
    }
    sumc=accumulate(c.begin(),c.end(),0);
    sumb=accumulate(b.begin(),b.end(),0);
    sumba=accumulate(ba.begin(),ba.end(),0);
    int o=max(sumc,sumb);
    int ans=max(o,sumba);
    if (ans==sumc){
        cout<<"chest";
    }
    else if(ans==sumb){
        cout<<"biceps";
    }
    else{
        cout<<"back";
    }
    // cout<<ans;
    return 0;
}