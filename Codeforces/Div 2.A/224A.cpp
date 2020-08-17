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
    int x,y,z,l,b,h;
    cin>>x>>y>>z;
    l=sqrt(x*z/y);
    b=sqrt(x*y/z);
    h=sqrt(y*z/x);
    cout<<4*(l+b+h);
    return 0;
}