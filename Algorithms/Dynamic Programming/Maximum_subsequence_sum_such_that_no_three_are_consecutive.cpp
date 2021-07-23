#include <bits/stdc++.h>
using namespace std;

int maxSum(vector <int> a){
    int n=a.size();
    vector <int> dp(n,0);

    if(n>=1) dp[0]=a[0];
    if (n>=2) dp[1]=a[0]+a[1];
    if (n>=3) dp[2]=max(max(dp[1],a[2]+a[1]),a[2]+a[0]);

    for(int i=3;i<n;i++){
        dp[i]=max(max(dp[i-1],a[i]+dp[i-2]),a[i]+a[i-1]+dp[i-3]);
    }    

    return dp[n-1];
}
int main(){
    vector <int> a={100, 1000, 100, 1000, 1};
    cout<<maxSum(a);
    return 0;
}
