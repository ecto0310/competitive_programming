// URL: https://atcoder.jp/contests/abc125/submissions/5166852
// Date: Sun, 28 Apr 2019 00:40:35 +0900
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
    vector<i64> suml(n), sumr(n);
    suml[0] = a[0];
    for (i64 i = 1; i < n; i++)
        suml[i] = __gcd(suml[i - 1], a[i]);
    sumr[n - 1] = a[n - 1];
    for (i64 i = n - 2; 0 <= i; i--)
        sumr[i] = __gcd(sumr[i + 1], a[i]);
    i64 ans = max(suml[n - 2], sumr[1]);
    for (i64 i = 1; i < n - 1; i++)
        ans = max(ans, __gcd(suml[i-1], sumr[i + 1]));
    cout << ans << endl;
    return 0;
}
