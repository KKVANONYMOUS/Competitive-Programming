#include <bits/stdc++.h>
using namespace std;


//Time Complexity:O(n*length)
//Space Complexity:O(n*length)
int MaxPieces(vector <int> arr,int totalLength){
    if (arr.size()==0 || totalLength<=0) return 0;

    vector <vector <int>> dp(arr.size(),vector <int> (totalLength+1,-1));

    for(int i=0;i<arr.size();i++){
        dp[i][0]=0;
    }

    for(int j=0;j<=totalLength;j++){
        if (arr[0]==j){
            dp[0][j]=1;
        }
    }

    for(int i=1;i<arr.size();i++){
        for(int j=1;j<=totalLength;j++){
            int including=-1;
            int excluding=-1;

            if(dp[i][j-arr[i]]!=-1 && arr[i]<=j){
                including=1+dp[i][j-arr[i]];
            }

            excluding=dp[i-1][j];
            dp[i][j]=max(including,excluding);
        }
    }

    return dp[arr.size()-1][totalLength];
}

int main(){
    int n;
    cin>>n;
    vector <int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int totalLength;
    cin>>totalLength;
    cout<<MaxPieces(arr,totalLength);
    return 0;
}