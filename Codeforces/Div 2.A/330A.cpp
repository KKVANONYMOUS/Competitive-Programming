#include <bits/stdc++.h>
using namespace std;

#define ll          long long
#define fl(i,a,n)   for(int i=a;i<n;i++)

void kkvanonymous(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
int main(){
    kkvanonymous();
    int r,c,x=0,flag=0;
    char a[11][11];
    cin>>r>>c;
    fl(i,0,r){
        fl(j,0,c){
            cin>>a[i][j];
        }
    }
    fl(i,0,r){
        fl(j,0,c){
            if(a[i][j]=='S'){
                flag=1;
            }
        }
        fl(j,0,c){
            if(a[i][j]!='#' && flag==0){
                a[i][j]='#';
                x++;
            }
        }
        flag=0;
    }
    flag=0;
     fl(i,0,c){
      fl(j,0,r){
        if(a[j][i]=='S'){
                flag=1;
            }
        }
        fl(j,0,r){
            if(a[j][i]!='#' && flag==0 && a[j][i]=='.'){ // no need of a[j][i]=='.'  wrote for debugging purposes
                a[j][i]='#';
                x++;
            }
        }
        flag=0;
    }
    cout<<x;
    return 0;
}