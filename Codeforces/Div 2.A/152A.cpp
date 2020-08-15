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
    int n,m;
    cin>>n>>m;
    vector<bool>ans(n,false);
    vector<string>s(n);
    fl(i,0,n){
        cin>>s[i];
    }
    fl(i,0,m){
            char max='0';
            fl(j,0,n){
                if(s[j][i]>max){
                    max=s[j][i];
                } 
            }
             fl(j,0,n){
                if(max==s[j][i]){
                    ans[j]=true;
                }
            }
    }
    cout<<count(ans.begin(),ans.end(),true);
    return 0;
}