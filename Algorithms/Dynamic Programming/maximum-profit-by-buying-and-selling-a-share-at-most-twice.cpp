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

//Time Complexity:O(n)
//Space Complexity:O(1)
//Using Valley-Peak Approach
 /*
                       80
                       /
        30            /
       /  \          25
      /    15       /
     /      \      /
    2        10   /
               \ /
                8
*/
int findProfitDP(vector <int> price,int n){
    int profit=0;

    for(int i=1;i<n;i++){
        int diff=price[i]-price[i-1];

        if(diff>0) profit+=diff;
    }

    return profit;
}
int main(){
    vector <int> price={ 2, 30, 15, 10, 8, 25, 80 };
    int n=price.size();
    cout<<findProfit(price,n);
    cout<<"\n";
    cout<<findProfitDP(price,n);
    return 0;
}