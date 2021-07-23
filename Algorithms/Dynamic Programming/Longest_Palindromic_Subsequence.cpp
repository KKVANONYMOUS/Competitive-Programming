#include <bits/stdc++.h>
using namespace std;


//Normal recursive way 
// Time Complexity=O(2^n);
// Space Complexity=O(n); 
int lps(string a,int start,int end){
    if (start>end) return 0;
    if(start==end) return 1;
    
    if(a[start]==a[end]){
        return 2+lps(a,start+1,end-1);
    }
    else{
        return max(lps(a,start,end-1),lps(a,start+1,end));
    }
}


//Recursive Top Down DP
// Time Complexity=O(n^2);
// Space Complexity=O(n^2); coz we use dp 2D array
int lpsRec(string a,int i,int j,vector <vector <int>> dp){
    if (i>j) return 0;
    if(i==j) return 1;
    
    if (dp[i][j]==-1){
        if(a[i]==a[j]){
            dp[i][j]= 2+lpsRec(a,i+1,j-1,dp);
        }
        else{
            dp[i][j]= max(lpsRec(a,i,j-1,dp),lpsRec(a,i+1,j,dp));
        }
    }

    return dp[i][j];
}

//Tabulation Bottom Up DP
// Time Complexity=O(n^2);
// Space Complexity=O(n^2); coz we use dp 2D array
int lpsTab(string a){
    int n=a.size();
    vector <vector <int>> dp(n,vector <int>(n,0));

    for(int i=0;i<n;i++){
        dp[i][i]=1;
    }

    for(int i=n-2;i>=0;i--){
        for(int j=i+1;j<n;j++){
            if (a[i]==a[j]){
                dp[i][j]=2+dp[i+1][j-1];
            }
            else{
                dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
            }
        }
    }

    return dp[0][n-1];
}

int main(){
    string a;
    cin>>a;
    vector <vector <int>> dp(a.size(),vector <int>(a.size(),-1));
    //cout<<lps(a,0,a.size()-1);
    //cout<<lpsRec(a,0,a.size()-1,dp);
    cout<<lpsTab(a);
    return 0;
}