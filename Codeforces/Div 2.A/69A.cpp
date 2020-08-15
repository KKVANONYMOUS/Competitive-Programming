#include <bits/stdc++.h>
using namespace std;

#define ll          long long
#define fl(i,a,n)   for(int i=a;i<n;i++)

void kkvanonymous(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
int main(){
    kkvanonymous();
    int n,sumx=0,sumy=0,sumz=0;
    cin>>n;
    int f[101][4];
    fl(i,0,n){
        fl(j,0,3){
            cin>>f[i][j];
        }
    }
    fl(i,0,n){
        sumx+=f[i][0];
        sumy+=f[i][1];
        sumz+=f[i][2];
    }
    if (sumx==0 && sumy==0 && sumy==0){
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
    
    return 0;
}