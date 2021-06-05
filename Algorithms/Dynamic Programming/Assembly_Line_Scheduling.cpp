#include <bits/stdc++.h>
using namespace std;

const int NUM_STATION=4;

//Recursive approach
//TC:O(2^NUM_STATION);
int carAssembly(int i,int j,int a[][NUM_STATION],int t[][NUM_STATION],int e[2],int x[2]){
    if(j==NUM_STATION-1) return a[i][j]+x[i];

    return a[i][j]+min(t[i][j+1]+carAssembly(!i,j+1,a,t,e,x),carAssembly(i,j+1,a,t,e,x));
}

//Bottom  Up Approach - DP Tabular Method
//TC:O(NUM_STATION);
int carAssemblyDP(int a[][NUM_STATION],int t[][NUM_STATION],int e[2],int x[2]){
    vector <int> L1(NUM_STATION);
    vector <int> L2(NUM_STATION);

    L1[0]=e[0]+a[0][0];
    L2[0]=e[1]+a[1][0];

    for(int i=1;i<NUM_STATION;i++){
        L1[i]=min(L1[i-1]+a[0][i],L2[i-1]+t[1][i]+a[0][i]);
        L2[i]=min(L2[i-1]+a[1][i],L1[i-1]+t[0][i]+a[1][i]);
    }

    return min(L1[NUM_STATION-1]+x[0],L2[NUM_STATION-1]+x[1]);
}
int main() {
    int a[][NUM_STATION] = {{4, 2, 3, 2},
                            {2, 10, 1, 4}};
    int t[][NUM_STATION] = {{0, 7, 4, 5},
                            {0, 9, 2, 8}};
    int e[] = {10, 12}, x[] = {18, 7};

    int ans=INT_MAX;
    for(int i=0;i<2;i++){
        ans=min(ans,e[i]+carAssembly(i,0,a,t,e,x));
    }
    cout<<ans<<"\n";
    cout<<carAssemblyDP(a,t,e,x);
}
