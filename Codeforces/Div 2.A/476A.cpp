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
    int n, m, min = 10005;
    cin >> n >> m;
    fl(i, 0, n+1)
    {
        fl(j, 0, n+1)
        {
            if ((i * 2 + j * 1) == n && (i + j) % m == 0 && (i + j) < min)
            {
                min = i + j;
            }
        }
    }
    if (min == 10005)
    {
        cout << -1;
    }
    else
    {
        cout << min;
    }

    return 0;
}