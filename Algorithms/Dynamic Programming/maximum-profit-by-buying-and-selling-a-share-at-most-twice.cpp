#include <bits/stdc++.h>
using namespace std;


//Time Complexity:O(n)
//Space Complexity:O(n)
int findProfit(vector <int> price,int n){
    vector <int> profit(n,0);

    int max_el=price[n-1];
    for(int i=n-2;i>=0;i--){
        if(price[i]>max_el) max_el=price[i];

        profit[i]=max(profit[i+1],max_el-price[i]);
    }
    
    //for(auto x:profit) cout<<x<<" ";

    int min_el=price[0];
    for(int i=1;i<n;i++){
        if(price[i]<min_el) min_el=price[i];

        profit[i]=max(profit[i-1],profit[i]+price[i]-min_el);
    }
    //cout<<"\n";
    //for(auto x:profit) cout<<x<<" ";
    //cout<<"\n";
    return profit[n-1];
}

int main(){
    vector <int> price={2,1,4,3,6,5,8};
    int n=price.size();
    cout<<findProfit(price,n);
    return 0;
}