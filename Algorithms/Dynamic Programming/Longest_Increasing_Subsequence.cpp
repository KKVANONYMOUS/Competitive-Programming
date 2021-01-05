#include <bits/stdc++.h>
using namespace std;


int lis(vector <int> a,int n){
    vector <int> dp(n,1);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if (a[j]<a[i] && dp[i]<dp[j]+1) dp[i]=dp[j]+1;
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
    cout<<lis(a,n);
    return 0;
}