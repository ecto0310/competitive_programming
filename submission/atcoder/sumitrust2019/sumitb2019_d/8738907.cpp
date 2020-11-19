// URL: https://atcoder.jp/contests/sumitrust2019/submissions/8738907
// Date: Sun, 01 Dec 2019 21:43:36 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  string s;
  cin >> n >> s;
  vector<i64> l(n + 1), r(n + 1);
  for (i64 i = 0; i < n; i++)
    l[i + 1] = (l[i] | (1 << (s[i] - '0')));
  for (i64 i = n; 0 < i; i--)
    r[i - 1] = (r[i] | (1 << (s[i - 1] - '0')));
  set<i64> cnt[10];
  for (i64 i = 0; i < n; i++)
  {
    for (i64 j = 0; j < 10; j++)
      if (l[i] & (1 << j))
        for (i64 k = 0; k < 10; k++)
          if (r[i + 1] & (1 << k))
            cnt[s[i] - '0'].insert(j * 10 + k);
  }
  i64 ans = 0;
  for (i64 i = 0; i < 10; i++)
    ans += cnt[i].size();
  cout << ans << endl;
  return 0;
}
