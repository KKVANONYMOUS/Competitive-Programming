#include <bits/stdc++.h>
using namespace std;


//Time Complexity:O(n)
//Space Complexity:O(n)
int MaxSum(vector <int> arr){
    if (arr.size()==0) return 0;

    vector <int> dp(arr.size(),0);
    dp[0]=arr[0];

    dp[1]=arr[1]>arr[0]?arr[1]:arr[0];

    for(int i=2;i<arr.size();i++){
        dp[i]=max(arr[i]+dp[i-2],dp[i-1]);
    }

    return dp[arr.size()-1];
}

int main(){
    int n;
    cin>>n;
    vector <int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<MaxSum(arr);
    return 0;
}