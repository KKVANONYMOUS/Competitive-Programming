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
    int n,x;
    cin>>n;
    vi a;
    fl(i,0,n){
        cin>>x;
        a.pb(x);
    }
    vi fset;
    vi sset;
    vi tset;
    fl(i,0,n){
        if (a[i]<0){
            fset.pb(a[i]);
        }
        else if (a[i]==0){
            tset.pb(a[i]);
        }
        else{
            sset.pb(a[i]);
        }
    }
    if (sset.size()==0){
        fl(i,0,2){
            sset.pb(fset.back());
            fset.pop_back();
        }
    }
    if (fset.size()%2==0){
            tset.pb(fset.back());
            fset.pop_back();            
        }
    cout<<fset.size()<<" ";
    fl(i,0,fset.size()){
        cout<<fset[i]<<" ";
    }
    cout<<endl<<sset.size()<<" ";
    fl(i,0,sset.size()){
        cout<<sset[i]<<" ";
    }
    cout<<endl<<tset.size()<<" ";
    fl(i,0,tset.size()){
        cout<<tset[i]<<" ";
    }
    return 0;
}