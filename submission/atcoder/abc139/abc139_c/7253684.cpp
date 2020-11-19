// URL: https://atcoder.jp/contests/abc139/submissions/7253684
// Date: Sun, 01 Sep 2019 21:07:56 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<i64> h(n);
  for (i64 i = 0; i < n; i++)
    cin >> h[i];
  i64 ans = 0, now = 0;
  for (i64 i = n - 1; 0 < i; i--)
    if (h[i] <= h[i - 1])
      now++;
    else
    {
      ans = max(ans, now);
      now = 0;
    }
  cout << max(ans, now) << endl;
  return 0;
}
