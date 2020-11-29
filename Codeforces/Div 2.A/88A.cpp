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
#define sort(c) sort(all(c))
#define getUnique(c)  {sort(c);c.erase(unique(all(c)), c.end());}
#define MOD 1000000007
#define PI 3.14159265358979323846
#define INF 2000000000000000000

/*TEMPLATES*/
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
	cout << "["; for(int i = 0; i < sz(v); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}
template <typename A, typename B>
ostream &operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.F << ", " << p.S << ")"; }
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p) {
	cin >> p.F;
	return cin >> p.S;
}

/*NUMBER THEORY*/
namespace number_theory
{
    ll gcd(ll x, ll y)
    {
        if (x == 0)
            return y;
        if (y == 0)
            return x;
        return gcd(y, x % y);
    }

    bool isPrime(ll n)
    {
        if (n <= 1)
            return false;
        if (n <= 3)
            return true;

        if (n % 2 == 0 || n % 3 == 0)
            return false;

        for (ll i = 5; i * i <= n; i += 6)
            if (n % i == 0 || n % (i + 2) == 0)
                return false;

        return true;
    }

    bool prime[15000105];
    void sieve(int n)
    {
        for (ll i = 0; i <= n; i++)
            prime[i] = 1;
        for (ll p = 2; p * p <= n; p++)
        {
            if (prime[p] == true)
            {
                for (ll i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
        prime[1] = prime[0] = 0;
    }
    vll primelist;
    bool __primes_generated__ = 0;

    void genprimes(int n)
    {
        __primes_generated__ = 1;
        sieve(n + 1);
        for (ll i = 2; i <= n; i++)
            if (prime[i])
                primelist.push_back(i);
    }

    vll factors(ll n)
    {
        if (!__primes_generated__)
        {
            exit(1);
        }
        vll facs;

        for (ll i = 0; primelist[i] * primelist[i] <= n && i < primelist.size(); i++)
        {
            if (n % primelist[i] == 0)
            {
                while (n % primelist[i] == 0)
                {
                    n /= primelist[i];
                    facs.pb(primelist[i]);
                }
            }
        }
        if (n > 1)
        {
            facs.pb(n);
        }
        sort(facs);
        return facs;
    }
}

using namespace number_theory;

void kkvanonymous()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    genprimes(1.5e6);

//#ifdef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//#endif
}


ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 5240;
vll a(template_array_size);
vll b(template_array_size);
vll c(template_array_size);
string s, t;
ll ans = 0;

void solve(){
   string key[12]={"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "B", "H"};
   string a,b,c;
   cin>>a>>b>>c;
   vi found (12);
   fl(i,0,12){
       if (key[i]==a || key[i]==b || key[i]==c)
        found[i]=1;
   }
   fl(i,0,12){
       if (found[i]){
           if (found[(i+4)%12] && found[(i+7)%12]){
               cout<<"major";
               return;
           }
           else if (found[(i+3)%12] && found[(i+7)%12]){
               cout<<"minor";
               return;
           }
       }
   }
   cout<<"strange";

}

int main()
{
#ifdef kkvanonymous_time
    auto begin = chrono::high_resolution_clock::now();
#endif
    kkvanonymous();

    int t = 1;
    //cin>>t;
    while (t--)
        solve();

#ifdef kkvanonymous_time
    auto end = chrono::high_resolution_clock::now();
    cout << setprecision(4) << fixed;
    cout << "\nExecution time: " << chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
#endif
    return 0;
}