#include <bits/stdc++.h>
using namespace std;

int n=4;//total no of cities
int a[4][4]={ { 0, 10, 15, 20 },
              { 10, 0, 35, 25 },
              { 15, 35, 0, 30 },
              { 20, 25, 30, 0 } };

int dp[16][4]; // for memoization

int visted_all=(1<<n)-1;
int TSP(int mask,int pos){
    if(mask==visted_all) return a[pos][0];

    int ans=INT_MAX;
    for(int city=0;city<n;city++){

        //to check if the particular city is visted or not
        //if not visted than iterate over to next cities from that city
        if((mask & (1<<city))==0){
            int temp;
           
            if(dp[mask][city]!=-1){
                temp=dp[mask][city];
            }
            else {
                temp= a[pos][city] + TSP(mask | (1<<city),city);
                dp[mask][city]=temp;
            }
            ans=min(ans,temp);
        }
    }

    return ans;
}
int main(){

    for(int i=0;i<16;i++){
        for(int j=0;j<4;j++){
            dp[i][j]=-1;
        }
    }
    cout<<TSP(1,0);
    return 0;
}
