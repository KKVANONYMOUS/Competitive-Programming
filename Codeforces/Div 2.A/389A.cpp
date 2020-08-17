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
    int n, x, flag = 0;
    vi a;
    cin >> n;
    fl(i, 0, n)
    {
        cin >> x;
        a.pb(x);
    }
    while (flag != n)
    {
        sort(a.begin(), a.end());
        for (int i = n - 1; i > 0; i--)
        {
            if (a[i] > a[i - 1])
            {
                a[i] -= a[i - 1];
            }
        }
        flag = 0;
        fl(i, 0, n)
        {
            if (a[i] == a[0])
            {
                flag++;
            }
        }
    }
    cout << a[0] * n;
    return 0;
}