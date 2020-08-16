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
    int k,l,ans=0,flag=0;
    cin>>k>>l;
    while(l>=k){
        if (l%k!=0){;
            flag=1;
            break;
        }
        l=l/k;
        ans++;
    }
    if (l==1 && flag==0){
        cout<<"YES"<<endl<<ans-1;
    }
    else{
        cout<<"NO";
    }
    return 0;
}