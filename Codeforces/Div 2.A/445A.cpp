#include <bits/stdc++.h>
using namespace std;

#define ll          long long
#define fl(i,a,n)   for(int i=a;i<n;i++)
#define all(c)      c.begin(), c.end()
#define vi          vector<int>
#define vll         vector<ll>
#define pii         pair<int,int>
#define pb          push_back
#define mp          make_pair
#define f           first
#define s           second
#define mod         1000000007

void kkvanonymous(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

}

int main(){
    kkvanonymous();
    int n,m;
    char a[101][101];
    cin>>n>>m;
    fl(i,0,n){
        fl(j,0,m){
            cin>>a[i][j];
        }
    }
    fl(i,0,n){
        fl(j,0,m){
            if (a[i][j]=='.'){
                if ((i+j)%2==0){
                    a[i][j]='B';
                }
                else{
                    a[i][j]='W';
                }
            }
        }
    }
    fl(i,0,n){
        fl(j,0,m){
            cout<<a[i][j];
        }
        cout<<"\n";
    }
    return 0;
}