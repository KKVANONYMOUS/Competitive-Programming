#include <bits/stdc++.h>
using namespace std;

vector <vector <int>> dp(5,vector <int>(2,-1));
int minRemovals(vector <int> a,int k,int si,int ei){
    if(si>=ei) return INT_MAX;
    if(a[ei]-a[si]<=k) return 0;

    if(dp[si][ei]!=-1) return dp[si][ei];
    dp[si][ei]=1+min(minRemovals(a,k,si+1,ei),minRemovals(a,k,si,ei-1));
    return dp[si][ei];
}
int main(){
    vector <int> a={1, 5, 6, 2, 8};
    int k=2;

    sort(a.begin(),a.end());
    cout<<minRemovals(a,k,0,a.size()-1);
    return 0;
}