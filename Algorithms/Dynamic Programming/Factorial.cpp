#include <bits/stdc++.h>
using namespace std;

vector <int> dpMem(100005,-1);

//Using Memoization Method-Top Down DP
int facMem(int n){
    if (n==0 || n==1){
        dpMem[0]=dpMem[1]=1;
        return 1;
    }
    if (dpMem[n]!=-1) return dpMem[n];

    dpMem[n]=n*facMem(n-1);
    return dpMem[n];
}

vector <int> dpTab(100005,1);

//Using Tabulation Method-Bottom Up DP
void faceTab(int n){
    for(int i=1;i<=n;i++){  
        dpTab[i]=i*dpTab[i-1];
    }
    cout<<dpTab[n];
}

int main(){
    int n;
    cin>>n;
    cout<<facMem(n);
    //faceTab(n);
}
