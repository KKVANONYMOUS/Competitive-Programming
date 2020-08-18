#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fl(i, a, n) for (int i = a; i < n; i++)
#define all(c) c.begin(), c.end()
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define mod 1000000007

void kkvanonymous()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    kkvanonymous();
    ll y, k, n;
    cin >> y >> k >> n;
    ll a = y % k; //awesome logic
    a = (k - a) % k;
    if (a == 0)
    {
        a = k;
    }
    if (y + a > n)
    {
        cout << -1;
    }
    else
    {
        while (y + a <= n)
        {
            cout << a << " ";
            a += k;
        }
    }

    return 0;
}