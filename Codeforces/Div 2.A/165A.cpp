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
    int n,a[201][2],b=0,c=0,d=0,e=0,m=0;
    cin>>n;
    fl(i,0,n){
        fl(j,0,2){
            cin>>a[i][j];
        }
    }
    fl(i,0,n){
        b=0;
        c=0;
        d=0;
        e=0;
        fl(j,0,n){
            if (j!=i){
                if(a[j][0]<a[i][0] && a[j][1]==a[i][1]){
                    b++;
                }
                 if(a[j][0]>a[i][0] && a[j][1]==a[i][1]){
                    c++;
                }
                 if(a[j][1]<a[i][1] && a[j][0]==a[i][0]){
                    d++;
                }
                 if(a[j][1]>a[i][1] && a[j][0]==a[i][0]){
                    e++;
                }
            }
        }
        if (b>=1 && c>=1 && d>=1 && e>=1){
            m++;
        }
    }
    cout<<m;
    return 0;
}