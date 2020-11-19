// URL: https://atcoder.jp/contests/abc121/submissions/5176899
// Date: Sun, 28 Apr 2019 21:24:17 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
    i64 n, m, c;
    cin >> n >> m >> c;
    vector<i64> B(m);
    for (i64 i = 0; i < m; i++)
        cin >> B[i];
    vector<vector<i64>> a(n, vector<i64>(m));
    for (i64 i = 0; i < n; i++)
        for (i64 j = 0; j < m; j++)
            cin >> a[i][j];
    i64 ans = 0;
    for (i64 i = 0; i < n; i++)
    {
        i64 tmp = c;
        for (i64 j = 0; j < m; j++)
            tmp += a[i][j] * B[j];
        if (0 < tmp)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
