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
    int n, d, t[101], time = 0, c = 0, flag = 0;
    cin >> n >> d;
    fl(i, 0, n)
    {
        cin >> t[i];
    }
    sort(t, t + n);
    fl(i, 0, n)
    {
        time = time + t[i] + 10;
        c += 2;
    }
    time = time - 10;
    if (time > d)
    {
        cout << -1;
    }
    else
    {
        c -= 2;
        while (time <= d)
        {
            c += 1;
            time += 5;
            flag = 1;
        }
        if (flag == 1)
        {
            cout << c - 1;
        }
        else
        {
            cout << c;
        }
    }
    return 0;
}