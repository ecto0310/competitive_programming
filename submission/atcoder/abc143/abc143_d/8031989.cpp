// URL: https://atcoder.jp/contests/abc143/submissions/8031989
// Date: Sat, 19 Oct 2019 21:19:37 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<i64> l(n);
  for (i64 i = 0; i < n; i++)
    cin >> l[i];
  sort(l.begin(), l.end());
  i64 ans = 0;
  for (i64 i = 0; i < n; i++)
    for (i64 j = i + 1; j < n; j++)
    {
      i64 ma = lower_bound(l.begin(), l.end(), l[i] + l[j]) - l.begin();
      i64 mi = upper_bound(l.begin(), l.end(), abs(l[i] - l[j])) - l.begin();
      ans += ma - mi - (mi <= i && i <= ma) - (mi <= j && j <= ma);
    }
  cout << ans / 3 << endl;
  return 0;
}
