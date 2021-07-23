#include <bits/stdc++.h>
using namespace std;

//Time Complexity:O(n*sum)
//Space Complexity:O(n*sum)
int countForSubset(vector <int> a,int sum){
    if(a.size()==0 || sum<=0 ) return 0;
    
    vector <vector <int>> dp(a.size(),vector <int> (sum+1));

    for(int i=0;i<a.size();i++){
        dp[i][0]=1;
    }

    for(int j=0;j<=sum;j++){
        if (a[0]==j){
            dp[0][j]=1;
        }
    }

    for(int i=1;i<a.size();i++){
        for(int j=0;j<=sum;j++){
            int including=0;
            int excluding=0;

            if(j>=a[i]){
                including=dp[i-1][j-a[i]];
            }

            excluding=dp[i-1][j];
            dp[i][j]=including+excluding;
        }
    }
    for(auto x:dp){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return dp[a.size()-1][sum];
}

int Target_Sum(vector <int> a,int targetSum){
    int totalSum=accumulate(a.begin(),a.end(),0);

    if(totalSum<targetSum || (targetSum+totalSum)%2!=0) return 0;
    
    int sumToCheck=(targetSum + totalSum)/2;
    return countForSubset(a,sumToCheck);
}
int main(){
    int n;
    cin>>n;
    vector <int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int targetSum;
    cin>>targetSum;
    cout<<Target_Sum(a,targetSum);
    return 0;
}