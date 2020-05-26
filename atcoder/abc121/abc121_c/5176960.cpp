// URL: https://atcoder.jp/contests/abc121/submissions/5176960
// Date: Sun, 28 Apr 2019 21:28:25 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
    i64 n, m;
    cin >> n >> m;
    vector<pair<i64, i64>> d(n);
    for (i64 i = 0; i < n; i++)
        cin >> d[i].first >> d[i].second;
    sort(d.begin(), d.end());
    i64 ans = 0, cnt = 0;
    for (pair<i64, i64> t : d)
    {
        if (cnt + t.second < m)
            ans += t.first * t.second;
        else
        {
            ans += t.first * max(0LL, (m - cnt));
            break;
        }
        cnt += t.second;
    }
    cout << ans << endl;
    return 0;
}
