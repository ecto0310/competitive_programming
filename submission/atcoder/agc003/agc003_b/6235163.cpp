// URL: https://atcoder.jp/contests/agc003/submissions/6235163
// Date: Thu, 04 Jul 2019 18:22:42 +0900
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
  i64 ans = 0;
  for (i64 i = 0; i < n; i++)
  {
    ans += a[i] / 2;
    a[i] %= 2;
    if (i < n - 1 && 0 < a[i] && 0 < a[i + 1])
    {
      ans++;
      a[i]--;
      a[i + 1]--;
    }
  }
  cout << ans << endl;
  return 0;
}
