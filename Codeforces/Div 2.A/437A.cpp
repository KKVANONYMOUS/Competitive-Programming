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
bool compare(string s1,string s2){
    return s1.size()<s2.size();
}
int main(){
    kkvanonymous();
    vector <string> a;
    string s;
    fl(i,0,4){
        cin>>s;
        a.pb(s);
    }
    sort(a.begin(),a.end(),compare);
    int cnt=0;
    fl(i,0,4){
        if (a[i]!=a[0] && (a[i].size()-2)>=(2*(a[0].size()-2))){
            cnt++;
        }
    }
    int c=0;
    fl(i,0,4){
       if (a[i]!=a[3] && (2*(a[i].size()-2))<=(a[3].size()-2)){
            c++;
            }
        }

    if (cnt==3 && c!=3){
        cout<<a[0][0];
    }
    else if(c==3  && cnt!=3){
        cout<<a[3][0];
    }
    else{
        cout<<'C';
    }
    return 0;
}