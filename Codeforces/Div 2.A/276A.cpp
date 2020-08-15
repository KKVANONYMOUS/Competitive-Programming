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
    ll n,k,a[10001][2],max=-9999999999,joy;
    cin>>n>>k;
    fl(i,0,n){
        fl(j,0,2){
            cin>>a[i][j];
        }
    }
    fl(i,0,n){
        if(a[i][1]>k ){
            joy=a[i][0]-a[i][1]+k;
        }
        else{
            joy=a[i][0];
        }
        if(joy>max){
            max=joy;
        }
    }
    cout<<max;
    return 0;
}