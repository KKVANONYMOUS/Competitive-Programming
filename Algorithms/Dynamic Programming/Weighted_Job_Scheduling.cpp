#include <bits/stdc++.h>
using namespace std;

//Linear Search
//int getPreviousJob(int i,vector <vector <int>> a){
//    for(int j=i-1;j>=0;j--){
//        if(a[j][1]<=a[i][0]) return j;
//    }
//
//    return -1;
//}

//Binary Saerch
int getPreviousJob(int i,vector <vector <int>> a){
    int l=0,r=i-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(a[mid][1]<=a[i][0]){
            if(a[mid+1][1]<=a[1][0]){
                l=mid+1;
            }
            else return mid;
        }
        else r=mid-1;
    }

    return -1;
}

bool comp(vector <int> &a,vector <int> &b){
    return a[1]<b[1];
}
int maxProfit(vector <vector<int>> a){
    int n=a.size();
    vector <int> dp(n,0);
    sort(a.begin(),a.end(),comp);
    dp[0]=a[0][2];

    for(int i=1;i<n;i++){
        int index=getPreviousJob(i,a);
        dp[i]=dp[i-1];
        if(index!=-1) dp[i]=max(dp[i],dp[index]+a[i][2]);
    }

    return dp[n-1];
}
int main(){
    vector <vector <int>> a={{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
    cout<<maxProfit(a);
    return 0;
}