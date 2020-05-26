// URL: https://codeforces.com/contest/1284/submission/68178816
// Date: Sat, 04 Jan 2020 21:50:35 +0900
// Language: GNU C++17
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<i64> mi, ma;
  i64 ans = 0;
  for (i64 i = 0; i < n; i++)
  {
    i64 l;
    cin >> l;
    bool ok = false;
    i64 tmi = 1e9, tma = 0;
    for (i64 j = 0; j < l; j++)
    {
      i64 s;
      cin >> s;
      tmi = min(tmi, s);
      if (j != 0 && tmi < s)
        ok = true;
      tma = max(tma, s);
    }
    if (ok)
      ans += n;
    else
    {
      ma.push_back(tma);
      mi.push_back(tmi);
    }
  }
  sort(mi.begin(), mi.end());
  sort(ma.begin(), ma.end());
  i64 cnt = 0, sz = ma.size();
  for (i64 i = 0; i < sz; i++)
  {
    while (cnt < sz && ma[cnt] <= mi[i])
      cnt++;
    ans += n - cnt;
  }
  cout << ans << "\n";
  return 0;
}
