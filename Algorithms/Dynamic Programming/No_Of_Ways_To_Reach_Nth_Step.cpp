#include <bits/stdc++.h>
using namespace std;


vector <int> dp(10005,-1);

int findNoOfWays(int n){
    if(n==0) return 0;
    if (n==1){
        dp[1]=1;
        return 1;
    }
    else if (n==2){
        dp[2]=2;
        return 2;
    }
    if (dp[n]!=-1) return dp[n];

    dp[n]=findNoOfWays(n-1)+findNoOfWays(n-2);
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    cout<<findNoOfWays(n);
    return 0;
}