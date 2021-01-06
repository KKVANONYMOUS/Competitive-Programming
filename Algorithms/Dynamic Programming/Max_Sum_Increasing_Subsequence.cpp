#include <bits/stdc++.h>
using namespace std;


int mis(vector <int> a,int n){
    vector <int> dp=a;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if (a[j]<a[i] && dp[i]<dp[j]+a[i]) dp[i]=dp[j]+a[i];
        }
    }
    sort(dp.begin(),dp.end());
    return dp.back();
}
int main(){
    int n;
    cin>>n;
    vector <int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<mis(a,n);
    return 0;
}