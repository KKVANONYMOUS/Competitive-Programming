#include <bits/stdc++.h>
using namespace std;

bool isPalindromic(string s,int i,int j){
   while(i<j){
       if(s[i]!=s[j]) return false;
       i++;
       j--;
   }

   return true;
}

//Time Complexity:O(n^3)
//Space Complexity:O(n^2)
int main(){
    string s;
    cin>>s;
    int n=s.size();
    vector <vector <int>> dp(n,vector <int> (n,0));
    vector <vector <bool>> p(n,vector <bool> (n,false));

    for(int i=0;i<n;i++){
        p[i][i]=true;
    }

    for(int d=1;d<n;d++){
        for(int i=0;i<n-d;i++){
            int j=i+d;
            if(d==1){
                if(s[i]==s[j]) p[i][j]=true;
            }
            else if(s[i]==s[j] and p[i+1][j-1]){
                p[i][j]=true;
            }

            if(p[i][j]) dp[i][j]=0;
            else{
                
                dp[i][j]=INT_MAX;
                for(int k=i;k<=j-1;k++){
                    dp[i][j]=min(dp[i][j],1+dp[i][k]+dp[k+1][j]);
                }
            } 
        }
    }

    for(auto x:dp){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<"\n";
    }
    cout<<dp[0][n-1];
}