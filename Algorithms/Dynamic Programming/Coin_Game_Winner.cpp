#include <iostream>
#include <vector>
using namespace std;

bool winner(int n,int x,int y,int curr){
    if(n<=0) return !curr;
    if(n==1 or n==x or n==y) return !curr;

    return winner(n-1,x,y,!curr) || winner(n-x,x,y,!curr) || winner(n-y,x,y,!curr);
}

bool winnerDP(int n,int x,int y){
    vector <bool> dp(n+1,0);
    dp[0]=false;
    dp[1]=true;

    for(int i=2;i<=n;i++){
        if(i-1>=0 and !dp[i-1]) dp[i]=true;
        else if(i-x>=0 and !dp[i-x]) dp[i]=true;
        else if(i-y>=0 and !dp[i-y]) dp[i]=true;
        else dp[i]=false;
    }

    return dp[n];
}
int main(){
    int n=2,x=3,y=4;
    int curr=0;
    if(winnerDP(n,x,y)) cout<<"A";
    else cout<<"B";
    return 0;
}