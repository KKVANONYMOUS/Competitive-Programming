#include <bits/stdc++.h>
using namespace std;

#define ll          long long int
#define fl(i,a,n)   for(int i=a;i<n;i++)

void kkvanonymous(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
int main(){
    kkvanonymous();
    int n,t[31][3],c=0;
    cin>>n;
    fl(i,0,n){
        fl(j,0,2){
            cin>>t[i][j];
        }
    }
    fl(i,0,n){
        fl(j,0,n){
            if (i!=j){
                if (t[i][0]==t[j][1]){
                    c++;
                }
            }
            
        }
    }
    cout<<c;
    return 0;
}