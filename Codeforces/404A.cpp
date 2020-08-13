#include <bits/stdc++.h>
using namespace std;

#define ll          long long
#define fl(i,a,n)   for(int i=a;i<n;i++)
#define vi          vector<int>
#define vll         vector<ll>
#define pb          push_back
#define mod         1000000007

void kkvanonymous(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

int main(){
    kkvanonymous();
    int n,flag=0;
    char a[301][301],t,s;
    cin>>n;
    fl(i,0,n){
        fl(j,0,n){
            cin>>a[i][j];
        }
    }
    t=a[n/2][n/2];
    s=a[0][1];
    fl(i,0,n){
        fl(j,0,n){
                if (j==i){
                    if (a[i][j]!=t){
                        flag=1;
                    }
                }
                else if (j==(n-i-1)){
                    if (a[i][j]!=t){
                        flag=1;
                    }
                }
                else{
                    if(a[i][j]!=s){
                        flag=1;
                    }   
                } 
            
        }
    }
    if (flag==0 && t!=s){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}