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
    int n,cnt=0;
    string x;
    vector<string> a{"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE","0","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17"};
    cin>>n;
    vector<string>::iterator it;
    fl(i,0,n){
        cin>>x;
        it = find(all(a), x);
        if (it!=a.end()){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}