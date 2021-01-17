#include <bits/stdc++.h>
using namespace std;


//Time Complexity:O(n*rodLength)
//Space Complexity:O(n*rodLength)
//Unbounded, coz we can use a weight more than once
int RodCutting(vector <int> pieces,vector <int> profit,int rodLength){
    if (pieces.size()==0 || profit.size()==0 || rodLength<=0) return 0;

    vector <vector <int>> dp(pieces.size(),vector <int> (rodLength+1,0));

    int maxCount=0;
    for(int i=0;i<pieces.size();i++){
        for(int j=1;j<=rodLength;j++){
            int includingRodPiece=0;
            int excludingRodPiece=0;

            if(pieces[i]<=j){
                includingRodPiece=profit[i]+dp[i][j-pieces[i]];
            }

            if(i>0){
                excludingRodPiece=dp[i-1][j];
            }
            
            dp[i][j]=max(includingRodPiece,excludingRodPiece);
        }

        maxCount=max(dp[i][5],maxCount);
    }

    return maxCount;
}

int main(){
    int n;
    cin>>n;
    vector <int> pieces(n);
    vector <int> profit(n);
    for(int i=0;i<n;i++) cin>>pieces[i];
    for(int i=0;i<n;i++) cin>>profit[i];
    int rodLength;
    cin>>rodLength;
    cout<<RodCutting(pieces,profit,rodLength);
    return 0;
}