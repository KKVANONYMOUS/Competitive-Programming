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
    int n;
    vi a;
    cin>>n;
        if (n<=1 || n%2!=0){
        cout<<-1;
    }
    else{
        for(int i=1;i<=n-1;i+=2){
        a.pb(i+1);
        a.pb(i);
    }

    fl(i,0,a.size()){
        cout<<a[i]<<" ";
    }
    }
    
    return 0;
}