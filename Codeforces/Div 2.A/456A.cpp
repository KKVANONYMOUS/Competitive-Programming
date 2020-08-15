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
    ll n;
    bool flag=0;
    cin>>n;
    pair <int,int> a[n];
    fl(i,0,n){
       cin>>a[i].first>>a[i].second;
    }
    sort(a,a+n);
    fl(i,0,n-1){
        if (a[i].second>a[i+1].second){
            flag=1;
        }
    }
    if(flag){
        cout<<"Happy Alex";
    }
    else{
        cout<<"Poor Alex";
    }
    return 0;
}