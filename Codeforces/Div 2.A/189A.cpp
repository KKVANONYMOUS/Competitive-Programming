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
    int n,c=0,b;
    vi a;
    cin>>n;
    fl(i,0,3){
        cin>>b;
        a.pb(b);
    }
    sort(a.begin(),a.end());
    int m=n/a[0];
    for(int x=m;x>=0;x--){//awesome logic
        for(int y=0;y<=m;y++){
            int z=abs((n-(a[0]*x+a[1]*y))/a[2]);
            if((a[0]*x+a[1]*y+a[2]*z)==n){
                c=max(c,x+y+z);
            }
        }
    }
    cout<<c;
    return 0;
}