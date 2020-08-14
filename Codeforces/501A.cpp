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
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int m=max(3*a/10,a-a/250*c);
    int v=max(3*b/10,b-b/250*d);
    if (m!=v){
        if (max(m,v)==m){
            cout<<"Misha";
        }
        else{
            cout<<"Vasya";
        }
    }
    else{
        cout<<"Tie";
    }
    return 0;
}