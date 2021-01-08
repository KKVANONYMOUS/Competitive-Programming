#include <bits/stdc++.h>
using namespace std;


//Normal recursive approach
int E_DRec(string a,string b,int la,int lb){
    if(a==b) return 0;
    if (la==0) return lb;
    if (lb==0) return la;
    if(a[la-1]==b[lb-1]) return E_DRec(a,b,la-1,lb-1);
    return 1 + min(E_DRec(a,b,la-1,lb-1),min(E_DRec(a,b,la,lb-1),E_DRec(a,b,la-1,lb)));
}

//Tabulation Bottom Up DP
// Time Complexity=O(n*m);
// Space Complexity=O(n*m); coz we use dp 2D array
int E_D(string a,string b,int la,int lb){
    if(a==b) return 0;
    if (la==0) return lb;
    if (lb==0) return la;
    
    vector <vector <int>> dp(a.size()+1,vector <int>(b.size()+1));  

    for(int i=0;i<la+1;i++){
        dp[i][0]=i;
    } 
    for(int i=0;i<lb+1;i++){
        dp[0][i]=i;
    } 

    for(int i=1;i<la+1;i++){
        for(int j=1;j<lb+1;j++){
            if (a[i-1]==b[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=1+min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));
            }
        }
    } 

    return dp[la][lb];
}

int main(){
    string a,b;
    cin>>a>>b;
    //cout<<E_DRec(a,b,a.size(),b.size());
    cout<<E_D(a,b,a.size(),b.size());
    return 0;
}