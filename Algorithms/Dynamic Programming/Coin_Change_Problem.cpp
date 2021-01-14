#include <bits/stdc++.h>
using namespace std;


//Time Complexity:O(n*sum)
//Space Complexity:O(n*sum)
//Unbounded, coz we can use a weight more than once
int CoinChange(vector <int> coins,int sum){
    if (coins.size()==0 || sum<=0) return 0;

    vector <vector <int>> dp(coins.size(),vector <int> (sum+1,1));

    for(int i=1;i<coins.size();i++){
        for(int j=1;j<=sum;j++){
            if (j<coins[i]){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i][j-coins[i]]+dp[i-1][j];
            }
        }
    }

    return dp[coins.size()-1][sum];
}

int main(){
    int n;
    cin>>n;
    vector <int> coins(n);
    for(int i=0;i<n;i++) cin>>coins[i];
    int sum;
    cin>>sum;
    cout<<CoinChange(coins,sum);
    return 0;
}