#include <bits/stdc++.h>
using namespace std;


//Recursive way Top Down DP
// Time Complexity=O(n*m);
// Space Complexity=O(n*m); coz we use dp 2D array
int lcsRe(string a,string b,int la,int lb,vector <vector <int>> dp){
    if (la==0 || lb==0) return 0;

    if (dp[la][lb]==-1){
        if (a[la-1]==b[lb-1]) dp[la][lb]= 1+lcsRe(a,b,la-1,lb-1,dp);
        else{
            dp[la][lb]=max(lcsRe(a,b,la,lb-1,dp),lcsRe(a,b,la-1,lb,dp));
        }
    }
    
    return dp[la][lb];
}

//Tabulation Bottom Up DP
// Time Complexity=O(n*m);
// Space Complexity=O(n*m); coz we use dp 2D array
int lcsTab(string a,string b,int la,int lb){
    if (la==0 || lb==0) return 0;

    vector <vector <int>> dp(a.size()+1,vector <int>(b.size()+1,0));   

    for(int i=1;i<a.size()+1;i++){
        for(int j=1;j<b.size()+1;j++){
            if (a[i-1]==b[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    } 

    return dp[a.size()][b.size()];
}

int main(){
    string a,b;
    cin>>a>>b;
    vector <vector <int>> dp(a.size()+1,vector <int>(b.size()+1,-1));
    //cout<<lcsRe(a,b,a.size(),b.size(),dp);
    cout<<lcsTab(a,b,a.size(),b.size());
    return 0;
}