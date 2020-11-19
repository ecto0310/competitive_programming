// URL: https://atcoder.jp/contests/abc125/submissions/5166603
// Date: Sun, 28 Apr 2019 00:23:22 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
    i64 n;
    cin >> n;
    vector<i64> a(n);
    for (i64 i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<i64>> dp(n + 1, vector<i64>(2, -1e18));
    dp[0][0] = 0;
    for (i64 i = 0; i < n; i++)
    {
        dp[i + 1][0] = max(dp[i][0] + a[i], dp[i][1] - a[i]);
        dp[i + 1][1] = max(dp[i][0] - a[i], dp[i][1] + a[i]);
    }
    cout << dp[n][0] << endl;
    return 0;
}
