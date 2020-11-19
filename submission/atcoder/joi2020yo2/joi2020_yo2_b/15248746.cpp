// URL: https://atcoder.jp/contests/joi2020yo2/submissions/15248746
// Date: Wed, 15 Jul 2020 07:07:09 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<pair<i64, i64>> s(n);
  for (i64 i = 0; i < n; i++)
    cin >> s[i].first >> s[i].second;
  sort(s.begin(), s.end());
  i64 ans = max(s[n - 1].first, s[n - 1].second);
  for (i64 i = n - 2; 0 <= i; i--)
    ans = max(ans + s[i + 1].first - s[i].first, s[i].second);
  cout << ans + s[0].first << endl;
  return 0;
}
