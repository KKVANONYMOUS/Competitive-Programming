#include <bits/stdc++.h>
using namespace std;


//Time Complexity:O(n)
//Space Complexity:O(n)
//Unbounded, coz we can use a weight more than once
int MinJump(vector <int> arr){
    if (arr.size()==0) return 0;

    vector <int> dp(arr.size(),INT_MAX);
    dp[0]=0;

    for(int i=0;i<arr.size()-1;i++){
        for(int j=i+1;j<=i+arr[i] && j<arr.size();j++){
            dp[j]=min(1+dp[i],dp[j]);
        }
    }

    return dp[arr.size()-1];
}

int main(){
    int n;
    cin>>n;
    vector <int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<MinJump(arr);
    return 0;
}