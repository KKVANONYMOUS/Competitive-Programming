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
    int n, m, flag = 1, side = 1;
    cin >> n >> m;
    fl(i, 0, n)
    {
        if (flag == 1)
        {
            fl(i, 0, m)
            {
                cout << '#';
            }
            cout << endl;
            flag = 2;
        }
        else if (flag == 2)
        {
            fl(i, 0, m)
            {
                if (i == (m - 1) && side == 1)
                {
                    cout << '#';
                }
                else if (i == 0 && side == 2)
                {
                    cout << '#';
                }
                else
                {
                    cout << '.';
                }
            }
            side = side == 1 ? 2 : 1;
            cout << endl;
            flag = 1;
        }
    }
    return 0;
}