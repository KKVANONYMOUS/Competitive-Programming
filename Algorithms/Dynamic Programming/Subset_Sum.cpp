#include <bits/stdc++.h>
using namespace std;


bool isSubsetSum(int n,int sum,vector <int> a){
    bool dp[n+1][sum+1];
    for(int i=0;i<=n;i++){
        dp[i][0]=true;
    }
    for(int j=1;j<=sum;j++){
        dp[0][j]=false;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if (j < a[i-1]) dp[i][j]=dp[i-1][j];
            else dp[i][j]=dp[i-1][j] || dp[i-1][j-a[i-1]];
        }
    }

    for (int i = 0; i <=n; i++)
     {
       for (int j = 0; j <= sum; j++)
          cout<<dp[i][j];
       cout<<"\n";
     }

    return dp[n][sum];
}

int main(){
    int n;
    cin>>n;
    vector <int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int sum;
    cin>>sum;
    if (isSubsetSum(n,sum,a)) cout<<"Found a subset with given sum";
    else cout<<"No subset with given sum";
    return 0;
}