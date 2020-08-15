#include <bits/stdc++.h>
using namespace std;

#define ll          long long
#define fl(i,a,n)   for(int i=a;i<n;i++)

void kkvanonymous(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
int main(){
    kkvanonymous();
    int n,m,min=10000;
    cin>>n>>m;
    int p[51];
    fl(i,0,m){
        cin>>p[i];
    }
    sort(p,p+m);
    fl(i,0,m-n+1){
        if (p[i+n-1]-p[i]<min){
            min=p[i+n-1]-p[i];
        }
    }
    cout<<min;
    return 0;
}