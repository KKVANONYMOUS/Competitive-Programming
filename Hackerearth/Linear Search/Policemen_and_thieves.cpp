#include <bits/stdc++.h>
using namespace std;

#define ll          long long
#define fl(i,a,n)   for(int i=a;i<n;i++)
#define fll(i,a,n)   for(ll i=a;i<n;i++)
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
void solve(){
    ll n,k;
    char a[1001][1001];
    cin>>n>>k;
    fll(i,0,n){
        fll(j,0,n){
            cin>>a[i][j];
        }
    }
    ll cnt=0;
    ll p,m;
     fll(i,0,n){
        fll(j,0,n){
            if (a[i][j]=='T'){
                ll m=0;
                m=max(m,(j-k));
                p=min((j+k),n-1);
                while(m<=p){
                    if (a[i][m]=='P'){
                        a[i][m]='#';
                        cnt++;
                        break;
                    }
                    m++;
                }
                
            }
        }
    }
    cout<<cnt<<"\n";
}
int main(){
    kkvanonymous();
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}