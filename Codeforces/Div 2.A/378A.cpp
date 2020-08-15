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
    int a,b,x=0,y=0,z=0;
    cin>>a>>b;
    fl(i,1,7){
        if(abs(i-a)<abs(i-b)){
            x++;
        }
        if(abs(i-b)<abs(i-a)){
            y++;
        }
        if (abs(i-a)==abs(i-b)){
            z++;
        }

    }
    cout<<x<<" "<<z<<" "<<y;
    return 0;
}