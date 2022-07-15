#include <bits/stdc++.h>
using namespace std;

unsigned long long bitexp(int base, int exp)
{
    long long unsigned ans = 1, p = base;

    while (exp)
    {
        int bit = exp & 1;
        if (bit == 1)
        {
            ans *= p;
        }

        p *= p;
        exp >>= 1;
    }

    return ans;
}

unsigned long long cnt(string &num, int n, bool isTight)
{
    if (isTight == 0)
    {
        return bitexp(10, n);
    }

    if (n == 0)
        return 1;
    int upper_limit = num[num.size() - n] - '0';
    unsigned long long ans = 0;
    for (int digit = 0; digit <= upper_limit; digit++)
    {
        ans += cnt(num, n - 1, digit == upper_limit);
    }

    return ans;
}
unsigned long long sum_dp(string &num, int n, bool isTight, vector<vector<unsigned long long>> &dp)
{
    if (n == 0)
        return 0;

    if (dp[n][isTight] != -1)
        return dp[n][isTight];

    int upper_limit = isTight ? num[num.size() - n] - '0' : 9;
    unsigned long long ans = 0;
    for (int digit = 0; digit <= upper_limit; digit++)
    {
        ans += digit * cnt(num, n - 1, isTight && (digit == upper_limit));
        ans += sum_dp(num, n - 1, isTight && (digit == upper_limit), dp);
    }

    return dp[n][isTight] = ans;
}

void solve()
{
    unsigned long long a, b;
    cin >> a >> b;
    if (a)
        a--;

    string A = to_string(a);
    string B = to_string(b);

    vector<vector<unsigned long long>> dp1(100, vector<unsigned long long>(2, -1));
    vector<vector<unsigned long long>> dp2(100, vector<unsigned long long>(2, -1));

    cout << sum_dp(B, B.size(), 1, dp1) - sum_dp(A, A.size(), 1, dp2) << "\n";
}

int main()
{

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}