// URL: https://atcoder.jp/contests/abc153/submissions/9739030
// Date: Sun, 26 Jan 2020 21:07:05 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, k;
  cin >> n >> k;
  vector<i64> h(n);
  for (i64 i = 0; i < n; i++)
    cin >> h[i];
  sort(h.begin(), h.end(), greater<i64>());
  i64 ans = 0;
  for (i64 i = k; i < n; i++)
    ans += h[i];
  cout << ans << endl;
  return 0;
}
