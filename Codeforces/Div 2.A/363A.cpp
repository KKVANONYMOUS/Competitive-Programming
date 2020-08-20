#include <bits/stdc++.h>
using namespace std;

#define ll          long long
#define fl(i,a,n)   for(int i=a;i<n;i++)
#define fll(i,a,n)  for(ll i=a;i<n;i++)
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
    ll n,x;
    cin>>n;
    if (n==0){
        cout<<"O-|-OOOO"<<"\n";
    }
    else{
    while(n!=0){
        x=n%10;
        n=n/10;
        if (x==0){
            cout<<"O-|-OOOO"<<"\n";
        }
        else if(x>0 && x<=4){
            string ans="O-|";
            int i=1;
            while(i<=x){
                ans+='O';
                i++;
            }
            ans+='-';
            i=1;
            while(i<=(4-x)){
                ans+='O';
                i++;
            }
            cout<<ans<<"\n";
        }
        else{
            string ans="-O|";
            int i=1;
            while(i<=(x-5)){
                ans+='O';
                i++;
            }
            ans+='-';
            i=1;
            while(i<=(9-x)){
                ans+='O';
                i++;
            }
            cout<<ans<<"\n";
        }
    }
    }
    return 0;
}