#include <bits/stdc++.h>
using namespace std;

int subProd(vector <int> a,int k){
    int n=a.size();
    vector <vector <int>> dp(n+1,vector <int>(k+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            int excluding=dp[i-1][j];

            int including=0;
            if(a[i-1]<=j and a[i-1]>0){
                including=1+dp[i-1][j/a[i-1]];
            }

            dp[i][j]=including+excluding;
        }
    }
    return dp[n][k];
}
int main(){
    vector <int> a={1,2,3,4};
    int k=10;
    cout<<subProd(a,k);
    return 0;
}
