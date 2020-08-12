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
    int n,x,max=0;
    vi a;
    vi min;
    cin>>n;
    fl(i,0,n){
        cin>>x;
        a.pb(x);
    }    
    fl(i,1,n-1){
        vi b;
        b=a;
        auto it=b.begin()+i;
        b.erase(it);
        max=0;
        fl(j,0,b.size()){
            if((b[j+1]-b[j])>max){
                max=b[j+1]-b[j];
            }
        }
        min.pb(max);
    }
    sort(min.begin(),min.end());
    cout<<min[0];
    return 0;
}