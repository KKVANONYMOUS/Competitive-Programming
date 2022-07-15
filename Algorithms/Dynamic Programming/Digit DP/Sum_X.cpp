#include <bits/stdc++.h>
using namespace std;

/**
 * Find the count of numbers between L and R which have sum of digits = X
 * 1<=L<=R<=10^18
 * 1<=X<=180
 */

long long dp[100][181][2];

// Memoized Top Down DP
long long calc_dp(int n, int x, bool isTight, string &num)
{
    if (x < 0)
        return 0;

    if (n == 0)
    {
        if (x == 0)
            return 1;
        return 0;
    }

    if (dp[n][x][isTight] != -1)
        return dp[n][x][isTight];

    long long cnt = 0;
    long long upper_limit = isTight ? num[num.size() - n] - '0' : 9;

    for (long long digit = 0; digit <= upper_limit; digit++)
    {
        cnt += calc_dp(n - 1, x - digit, isTight && (digit == upper_limit), num);
    }

    return dp[n][x][isTight] = cnt;
}

bool checkSum(long long num, long long x)
{
    long long sum = 0;
    while (num)
    {
        sum += num % 10;
        num /= 10;
    }

    return sum == x;
}

// Bruteforce
long long brute_force(long long limit, long long x)
{
    long long cnt = 0;
    for (long long num = 0; num <= limit; num++)
    {
        cnt += checkSum(num, x);
    }
    return cnt;
}

int main()
{
    memset(dp, -1, sizeof dp);
    string R = "11235";
    int x = 15;
    cout << brute_force(11235, x) << "\n";
    cout << calc_dp(R.size(), x, 1, R);
    return 0;
}
