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
    int min=999999;
    fl(i,0,n){
        int sum=0;
        fl(j,0,a[i]){
            cin>>x;
            sum+=x;
        }
        int cost=sum*5+15*a[i];
        if (cost<min){
            min=cost;
        }
    }
    cout<<min;
    return 0;
}