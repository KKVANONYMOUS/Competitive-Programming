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
    char s[1001];
    gets(s);
    int len = strlen(s), c = 0;
    sort(s, s + len);
    fl(i, 0, len)
    {
        if (s[i] >= 97 && s[i] <= 122)
        {
            if (s[i] != s[i + 1])
            {
                c++;
            }
        }
    }
    cout << c;
    return 0;
}