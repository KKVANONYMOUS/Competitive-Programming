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
    int a, b, c, c1, c2, c3, c4, c5, c6;
    cin >> a >> b >> c;
    c1 = a + b * c;
    c2 = a * (b + c);
    c3 = a * b * c;
    c4 = (a + b) * c;
    c5 = a + b + c;
    c6 = a * b + c;
    int comp[6] = {c1, c2, c3, c4,c5,c6};
    sort(comp, comp + 6);
    cout << comp[5];
    return 0;
}