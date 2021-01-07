#include <bits/stdc++.h>
using namespace std;


//Normal recursive approach
int lcsRec(string a,string b,int la,int lb,int count){
    if (la==0 || lb==0) return count;

    if (a[la-1]==b[lb-1]){
        count= lcsRec(a,b,la-1,lb-1,count+1);
    }

    int count1=lcsRec(a,b,la,lb-1,0);
    int count2=lcsRec(a,b,la-1,lb,0);

    return max(count,max(count1,count2));
}

//Tabulation Bottom Up DP
// Time Complexity=O(n*m);
// Space Complexity=O(n*m); coz we use dp 2D array
int lcs(string a,string b,int la,int lb){
    if (la==0 || lb==0) return 0;

    int maxLcs=0;

    vector <vector <int>> dp(a.size()+1,vector <int>(b.size()+1,0));   

    for(int i=1;i<a.size()+1;i++){
        for(int j=1;j<b.size()+1;j++){
            if (a[i-1]==b[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
                maxLcs=(maxLcs,dp[i][j]);
            }
            else{
                dp[i][j]=0;
            }
        }
    } 

    return maxLcs;
}

int main(){
    string a,b;
    cin>>a>>b;
    //cout<<lcsRec(a,b,a.size(),b.size(),0);
    cout<<lcs(a,b,a.size(),b.size());
    return 0;
}