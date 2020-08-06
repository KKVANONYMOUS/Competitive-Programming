#include <bits/stdc++.h>
using namespace std;

#define ll          long long int
#define fl(i,a,n)   for(int i=a;i<n;i++)

void kkvanonymous(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
int main(){
    kkvanonymous();
    int n,x;
    int sumStart;
    int sumEnd;
    int coins[101];
    cin>>n;
    fl(i,0,n){
        cin>>x;
        coins[i]=(int)x;
    }
    sort(coins,coins+n,greater<int>());
    fl(i,0,n){
        sumStart=0;
        sumEnd=0;
        sumStart=accumulate(coins,coins+i+1,sumStart);
        sumEnd=accumulate(coins+i+1,coins+n,sumEnd);
        if (sumStart>sumEnd){
            cout<<i+1;
            break;
        }
    }
    return 0;
}