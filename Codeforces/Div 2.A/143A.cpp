#include <bits/stdc++.h>
using namespace std;

/*DEBUGGER*/
#define deb(x)      cout << #x << "=" << x << endl
#define deb2(x, y)  cout << #x << "=" << x << "," << #y << "=" << y << endl

typedef long long            ll; 
typedef pair<int, int>       pii;
typedef pair<ll, ll>         pll;
typedef pair<string, string> pss;
typedef vector<int>          vi;
typedef vector<vi>           vvi;
typedef vector<pii>          vii;
typedef vector<ll>           vll;
typedef vector<vll>          vvll;

#define fl(i,a,n)   for(int i=a;i<n;i++)
#define fll(i,a,n)  for(ll i=a;i<n;i++)
#define tr(it, a)   for(auto it = a.begin(); it != a.end(); it++)
#define all(c)      c.begin(), c.end()
#define sz(a)       int((a).size())
#define pb          push_back
#define mp          make_pair
#define F           first
#define S           second
#define gcd(a,b)    __gcd(a,b)
#define sort(c)     sort(all(c))
#define MOD         1000000007
#define INF         2000000000000000000

void kkvanonymous(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
}

int main(){
    kkvanonymous();
    vector <pii> a;
    int x,y;
    fl(i,0,3){
        cin>>x>>y;
        a.pb({x,y});
    }
    int flag=0,b1=a[2].F,b2,b3,b4,m,n;
    while(!flag && min(m=min(b1,b2),n=min(b3,b4))>=0){
         b4=a[2].F-b1;
         b3=a[0].S-b4;
        if ((b1+b3)==a[1].F){
            b2=a[2].S-b3;
            if ((b2+b4)==a[1].S && (b1+b2)==a[0].F && b1!=b2 && b2!=b3 && b3!=b4 && b1!=b4 && b1!=b3 && b2!=b4 && max(m=max(b1,b2),n=max(b3,b4))<=9 && min(m=min(b1,b2),n=min(b3,b4))>=1){
                flag=1;
                break;
            }
        }
        if (!flag){
            b1--;
        }
    }
    if (flag){
        cout<<b1<<" "<<b2<<"\n";
        cout<<b3<<" "<<b4<<"\n";
    }
    else{
        cout<<-1;
    }
    return 0;
}