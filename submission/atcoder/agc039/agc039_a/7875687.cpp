// URL: https://atcoder.jp/contests/agc039/submissions/7875687
// Date: Sat, 05 Oct 2019 23:31:04 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  string s;
  i64 k;
  cin >> s >> k;
  i64 ans = 0;
  string tmp = s;
  for (i64 i = 1; i < tmp.size(); i++)
    if (tmp[i] == tmp[i - 1])
    {
      tmp[i] = '*';
      ans++;
    }
  i64 cnt = 0;
  tmp = tmp[tmp.size() - 1] + s;
  for (i64 i = 1; i < tmp.size(); i++)
    if (tmp[i] == tmp[i - 1])
    {
      tmp[i] = '*';
      cnt++;
    }
  bool ok = true;
  for (i64 i = 1; i < s.size(); i++)
    if (s[i] != s[i - 1])
      ok = false;
  if (s.size() == 1)
    cout << k / 2 << endl;
  else if (ok)
    cout << k * s.size() / 2 << endl;
  else
    cout << ans + cnt * (k - 1) << endl;
  return 0;
}
