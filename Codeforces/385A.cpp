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
    int n,c,a[101],max=0,d=0;
    cin>>n>>c;
    fl(i,0,n){
        cin>>a[i];
    }
    fl(i,0,n-1){
        if (a[i]>=(a[i+1]+c) && (a[i]-(a[i+1]+c))>max){
            max=a[i]-(a[i+1]+c);
          
        }
    }
    cout<<max;
    return 0;
}