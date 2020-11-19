// URL: https://atcoder.jp/contests/abc026/submissions/8991024
// Date: Tue, 17 Dec 2019 17:28:46 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<i64> boss[n];
  for (i64 i = 1; i < n; i++)
  {
    i64 b;
    cin >> b;
    boss[b - 1].push_back(i);
  }
  vector<i64> ans(n, 1);
  for (i64 i = n - 1; 0 <= i; i--)
    if (boss[i].size() != 0)
    {
      i64 ma = 0, mi = 1e9;
      for (i64 j : boss[i])
      {
        ma = max(ma, ans[j]);
        mi = min(mi, ans[j]);
      }
      ans[i] = ma + mi + 1;
    }
  cout << ans[0] << endl;
  return 0;
}
