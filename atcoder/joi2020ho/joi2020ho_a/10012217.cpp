// URL: https://atcoder.jp/contests/joi2020ho/submissions/10012217
// Date: Sun, 09 Feb 2020 23:00:05 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<pair<i64, i64>> a(n + 1);
  vector<i64> b(n);
  for (i64 i = 0; i < n + 1; i++)
  {
    cin >> a[i].first;
    a[i].second = i;
  }
  for (i64 i = 0; i < n; i++)
    cin >> b[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  vector<i64> left(n + 1), right(n + 1);
  for (i64 i = 0; i < n; i++)
  {
    left[i] = max(left[i], a[i].first - b[i]);
    left[i + 1] = left[i];
  }
  for (i64 i = n; 0 < i; i--)
  {
    right[i] = max(right[i], a[i].first - b[i - 1]);
    right[i - 1] = right[i];
  }
  vector<i64> ans(n + 1);
  ans[a[0].second] = right[1];
  ans[a[n].second] = left[n - 1];
  for (i64 i = 1; i < n; i++)
    ans[a[i].second] = max(left[i - 1], right[i + 1]);
  for (i64 i = 0; i < n + 1; i++)
    cout << ans[i] << " \n"[i == n];
}
