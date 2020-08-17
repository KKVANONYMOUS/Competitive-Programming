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
    int n,fs=0,ss=0;
    vector <string> a;
    string s;
    cin>>n;
    fl(i,0,n){
        cin>>s;
        a.pb(s);
    }
    string ft=a[0],st;
    fl(i,0,n){
        if (a[i]==ft){
            fs++;
        }
        else{
            st=a[i];
            ss++;
        }
    }
    if (max(fs,ss)==fs){
        cout<<ft;
    }
    else {
        cout<<st;
    }
    return 0;
}