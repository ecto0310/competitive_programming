// URL: https://atcoder.jp/contests/joi2020ho/submissions/10012232
// Date: Sun, 09 Feb 2020 23:00:14 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, k;
  string s;
  cin >> n >> k >> s;
  vector<i64> cntj(n, 1e9), poso(n + 1, -1), cnti(n, 1e9);
  i64 right = 0, cnt = 0, rm = 0;
  for (i64 left = 0; left < n; left++)
  {
    while (right <= n && cnt < k)
    {
      if (s[right] == 'J')
        cnt++;
      else
        rm++;
      right++;
    }
    if (s[left] == 'J')
    {
      if (cnt == k)
        cntj[right - 1] = rm;
      cnt--;
    }
    else
      rm--;
  }
  right = 0, cnt = 0, rm = 0;
  for (i64 left = 0; left < n; left++)
  {
    while (right <= n && cnt < k)
    {
      if (s[right] == 'I')
        cnt++;
      else
        rm++;
      right++;
    }
    if (s[left] == 'I')
    {
      if (cnt == k)
        cnti[left] = rm;
      cnt--;
    }
    else
      rm--;
  }
  cnt = 0;
  for (i64 i = 0; i < n; i++)
    if (s[i] == 'O')
    {
      poso[cnt] = i;
      cnt++;
    }
  for (i64 i = 1; i < n; i++)
    cntj[i] = min(cntj[i], cntj[i - 1] + 1);
  for (i64 i = n - 2; 0 <= i; i--)
    cnti[i] = min(cnti[i], cnti[i + 1] + 1);
  i64 ans = 1e9;
  for (i64 i = 0; i < cnt - k + 1; i++)
    if (0 < poso[i] && poso[i + k - 1] < n - 1)
      ans = min(ans, poso[i + k - 1] - poso[i] - k + 1 + cntj[poso[i] - 1] + cnti[poso[i + k - 1] + 1]);
  if (ans == 1e9)
    cout << -1 << endl;
  else
    cout << ans << endl;
  return 0;
}
