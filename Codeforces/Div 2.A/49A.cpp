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
    string a;
    getline(cin,a);
    string newStr=" ";
    fl(i,0,a.size()){
        if (a[i]!=' '){
            newStr+=a[i];
        }
    }
    int l=newStr.size()-1;
    if (newStr[l-1]=='a' || newStr[l-1]=='e' || newStr[l-1]=='i' || newStr[l-1]=='o' || newStr[l-1]=='u' || newStr[l-1]=='y' || newStr[l-1]=='A' || newStr[l-1]=='E' || newStr[l-1]=='I' || newStr[l-1]=='O' ||newStr[l-1]=='U' || newStr[l-1]=='Y'){
        cout<<"YES";
    }
    else cout<<"NO";
    return 0;
}