#include <bits/stdc++.h>
using namespace std;

#define ll          long long
#define fl(i,a,n)   for(int i=a;i<n;i++)

void kkvanonymous(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
int main(){
    kkvanonymous();
    vector <int> b;
    ll n,items,v,m;
    cin>>n>>v;
    fl(i,0,n){
        int flag=0;
        cin>>items;
        fl(j,0,items){
            cin>>m;
            if((v>m) && flag==0){
                flag=1;
                b.push_back(i);
            }
        }
    }
    cout<<b.size()<<endl;
    fl(i,0,b.size()){
        cout<<b[i]+1<<" ";
    }
    return 0;
}