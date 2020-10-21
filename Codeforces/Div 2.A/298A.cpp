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
    int n;
    string a;
    cin>>n>>a;
    int s1=1,s2=1,t=1,flag1=0,flag2=0;
    fl(i,0,n){
        if (a[i]=='R' && flag1==0){
            s1=i;
            flag1=1;
        }
        else if(a[i]=='L' && flag2==0){
            s2=i;
            flag2=1; 
        }
    }
    if (!flag1){
        fl(i,1,n){
        if (a[i]=='L' && a[i-1]=='.'){
            t=i-1;
            break;
        }
    }
    cout<<s2+1<<" "<<t+1;
    }
    if (!flag2){
        fl(i,0,n-1){
        if (a[i]=='R' && a[i+1]=='.'){
            t=i+1;
            break;
        }
    }
    cout<<s1+1<<" "<<t+1<<endl;
    }
    if (flag1 && flag2)
    {
        fl(i,0,n){
        if (a[i]=='R' && a[i+1]=='L'){
            t=i;
            break;
        }
    }
    cout<<s1+1<<" "<<t+1;
    }
    
   
    return 0;
}