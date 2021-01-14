#include <bits/stdc++.h>
using namespace std;


//Time Complexity:O(n*sum)
//Space Complexity:O(n*sum)
//Unbounded, coz we can use a weight more than once
int CoinChange(vector <int> coins,int sum){
    if (coins.size()==0 || sum<=0) return 0;

    vector <vector <int>> dp(coins.size(),vector <int> (sum+1,INT_MAX));

    for(int i=0;i<coins.size();i++){
        dp[i][0]=0;
    }

    for(int i=0;i<coins.size();i++){
        for(int j=1;j<=sum;j++){

            int includingCoin=INT_MAX;
            int excludingCoin=INT_MAX;
            
            if(coins[i]<=j){
                includingCoin=1+dp[i][j-coins[i]];
            }

            if(i>0){
                excludingCoin=dp[i-1][j];
            }

            dp[i][j]=min(includingCoin,excludingCoin);
            
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
    sort(coins.begin(),coins.end());
    cout<<CoinChange(coins,sum);
    return 0;
}