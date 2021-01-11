#include <bits/stdc++.h>
using namespace std;


//Time Complexity:O(n*capacity)
//Space Complexity:O(n*capacity)
//Bounded, coz we cannot use a weight more than once
int Knapsack(vector <int> weights,vector <int> profit,int capacity){
    if (weights.size()==0 || profit.size()==0 || capacity<=0) return 0;

    vector <vector <int>> dp(weights.size(),vector <int> (capacity+1,0));

    for(int j=0;j<=capacity;j++){
        dp[0][j]=profit[0];
    }

    for(int i=1;i<weights.size();i++){
        for(int j=1;j<=capacity;j++){
            if (j<i){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=max(profit[i]+dp[i-1][j-weights[i]],dp[i-1][j]);
            }
        }
    }

    return dp[weights.size()-1][capacity];
}

int main(){
    int n;
    cin>>n;
    vector <int> weights(n);
    vector <int> profit(n);
    for(int i=0;i<n;i++) cin>>weights[i];
    for(int i=0;i<n;i++) cin>>profit[i];
    int capacity;
    cin>>capacity;
    cout<<Knapsack(weights,profit,capacity);
    return 0;
}