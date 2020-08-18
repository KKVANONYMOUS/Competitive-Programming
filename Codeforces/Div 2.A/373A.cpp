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
    int k;
    cin>>k;
    char a[4][4];
    fl(i,0,4){
        fl(j,0,4){
            cin>>a[i][j];
        }
    }
    vector <char> s;
    fl(i,0,4){
        fl(j,0,4){
            if (a[i][j]!='.'){
            char t=a[i][j];
            int cnt=0;
            fl(m,0,4){
                fl(n,0,4){
                    if (a[m][n]==t){
                        cnt++;
                    }
                }
            }
            if (cnt>(2*k)){
                s.pb(t);
                }
            }
            
        }
    }
    if (s.size()==0){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}