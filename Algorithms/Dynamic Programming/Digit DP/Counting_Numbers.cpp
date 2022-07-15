#include <bits/stdc++.h>
using namespace std;

long long dp[20][10][2][2];
long long cnt_dp(string &num, int n, int x, bool leading_zeroes, bool isTight)
{
    if (n == 0)
        return 1;

    if (x != -1 and dp[n][x][leading_zeroes][isTight] != -1)
        return dp[n][x][leading_zeroes][isTight];

    int upper_limit = isTight ? (num[num.size() - n] - '0') : 9;
    long long cnt = 0;

    for (int digit = 0; digit <= upper_limit; digit++)
    {
        if ((digit == x) && !leading_zeroes)
            continue;
        cnt += cnt_dp(num, n - 1, digit, (digit == 0 && leading_zeroes), isTight && (digit == upper_limit));
    }

    return dp[n][x][leading_zeroes][isTight] = cnt;
}
void solve()
{
    long long a, b;
    cin >> a >> b;
    a--;

    string L = to_string(a);
    string R = to_string(b);

    memset(dp, -1, sizeof dp);
    long long cntL = cnt_dp(L, L.size(), -1, 1, 1);
    memset(dp, -1, sizeof dp);
    long long cntR = cnt_dp(R, R.size(), -1, 1, 1);
    cout << cntR - cntL << "\n";
}

int main()
{
    solve();
    return 0;
}