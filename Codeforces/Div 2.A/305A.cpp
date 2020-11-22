#include <bits/stdc++.h>
using namespace std;

/*DEBUGGER*/
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef vector<vll> vvll;

#define fl(i, a, n) for (int i = a; i < n; i++)
#define fll(i, a, n) for (ll i = a; i < n; i++)
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define all(c) c.begin(), c.end()
#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define gcd(a, b) __gcd(a, b)
#define sort(c) sort(all(c))
#define MOD 1000000007
#define INF 2000000000000000000

void kkvanonymous()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //#ifndef ONLINE_JUDGE
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);
    //#endif
}

int main()
{
    kkvanonymous();
    int n, x;
    vi a;
    cin >> n;
    int flag1=0,flag2=0;
    vi ans;
    fl(i, 0, n)
    {
        cin >> x;
        if (x>0 && x<10)
            flag1=1;
        else if (x>=10 && x<100 && x%10==0)
            flag2=1;
        a.pb(x);
    }
    int flag3=1,flag4=1,flag5=0;
    fl(i,0,n){
        if (a[i]==0 || a[i]==100){
            ans.pb(a[i]);
        }
        else if (a[i]>0 && a[i]<10 && flag1==1 && flag3==1){
            ans.pb(a[i]);
            flag3=0;
        }
        else if (a[i]>=10 && a[i]<100 && flag2==1 && flag4==1 && a[i]%10==0){
            ans.pb(a[i]);
            flag4=0;
        }
        else if(!flag1 && !flag2 && !flag5 && a[i]>=10 && a[i]<100 && a[i]%10!=0)
        {
            ans.pb(a[i]);
            flag5=1;
        }
            
    }
    cout<<ans.size()<<"\n";
    fl(i,0,ans.size()){
        cout<<ans[i]<<" ";
    }
    
    return 0;
}