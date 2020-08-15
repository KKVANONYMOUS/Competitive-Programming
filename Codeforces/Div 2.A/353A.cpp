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
    vector < pair <int,int> > a;
    int n,x,y;
    cin>>n;
    fl(i,0,n){
        cin>>x>>y;
        a.pb({x,y});
    }
    int s1=0,s2=0;
    bool ans=false;
    fl(i,0,n){
        s1+=a[i].f;
        s2+=a[i].s;
    }
    if (s1%2==0 && s2%2==0){
        cout<<0;
    }
    else if ((s1%2==0 && s2%2!=0) || (s1%2!=0 && s2%2==0)){
            cout<<-1;
        }
        
    else{
            fl(i,0,n){
                if ((a[i].f%2==0 && a[i].s%2!=0) || (a[i].f%2!=0 && a[i].s%2==0)){
                    ans=true;
                }
            }
            if (ans){
                cout<<1;
            }
            else{
                cout<<-1;
            }
        }
    return 0;
}