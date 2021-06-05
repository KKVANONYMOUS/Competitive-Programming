#include <bits/stdc++.h>
using namespace std;

int n=4,m=4;
vector <vector <int>> dp(n,vector <int> (m,-1));
//Recursive approach
//TC:O(n3^m);
int move(int i,int j,int a[][4]){
    if(i<0 || i>=n || j<0 ||j>=m) return 0;

    return a[i][j]+max(move(i,j+1,a),max(move(i+1,j+1,a),move(i-1,j+1,a)));
}

//Bottom  Up Approach -DP
//TC:O(n*m);
void moveDP(int a[][4],int n,int m,vector <vector <int>> &dp){
    for(int col=m-1;col>=0;col--){
        for(int row=0;row<n;row++){
            int right=col==m-1?0:dp[row][col+1];
            
            int diag_up=row==0 || col==m-1?0:dp[row-1][col+1];
            
            int diag_down=row==n-1 || col==m-1?0:dp[row+1][col+1];
            
            dp[row][col]=a[row][col]+max(right,max(diag_up,diag_down));
        }
    }
}
int main() {
    int a[][4]={{10, 33, 13, 15},
                  {22, 21, 4, 1},
                  {5, 0, 2, 3},
                  {0, 6, 14, 2}};

    //int ans=0;
    //for(int i=0;i<n;i++){
    //    ans=max(ans,move(i,0,a));
    //}
    vector <vector <int>> dp(n,vector <int>(m));
    moveDP(a,n,m,dp);
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,dp[i][0]);
    }
    cout<<ans;
}
