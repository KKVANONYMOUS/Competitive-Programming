#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fl(i, a, n) for (int i = a; i < n; i++)

void kkvanonymous()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main()
{
    kkvanonymous();
    ll n, x, y, y1, y2;
    cin >> n;
    if (n >= 0)
    {
        cout << n;
    }
    else
    {
        n = abs(n);
        x = n / 10;
        y1 = n / 10;
        y2 = y1 / 10;
        y = y2 * 10 + (n % 10);
        if (min(x, y) == 0)
        {
            cout << 0;
        }
        else
        {
            cout << "-" << min(x, y);
        }
    }
    return 0;
}