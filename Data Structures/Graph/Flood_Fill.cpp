#include<bits/stdc++.h>
using namespace std;


void flood_fill(vector <vector <int>> &a,int i,int j){
    if(i>=8 || j>=8 || i<0 || j<0 || a[i][j]!=2) return;

    a[i][j]=3;

    flood_fill(a,i+1,j);
    flood_fill(a,i-1,j);
    flood_fill(a,i,j+1);
    flood_fill(a,i,j-1);
}

int main(){
    vector <vector <int>> a={{1, 1, 1, 1, 1, 1, 1, 1},
               {1, 1, 1, 1, 1, 1, 0, 0},
               {1, 0, 0, 1, 1, 0, 1, 1},
               {1, 2, 2, 2, 2, 0, 1, 0},
               {1, 1, 1, 2, 2, 0, 1, 0},
               {1, 1, 1, 2, 2, 2, 2, 0},
               {1, 1, 1, 1, 1, 2, 1, 1},
               {1, 1, 1, 1, 1, 2, 2, 1},
               };
    flood_fill(a,4,4);

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}