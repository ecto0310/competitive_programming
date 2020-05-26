// URL: https://atcoder.jp/contests/abc138/submissions/7010484
// Date: Sun, 18 Aug 2019 22:49:22 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  string s, t;
  cin >> s >> t;
  vector<i64> pos[26];
  i64 ssize = s.size(), tsize = t.size();
  for (i64 i = 0; i < ssize; i++)
    pos[s[i] - 'a'].push_back(i);
  for (i64 i = 0; i < tsize; i++)
    if (pos[t[i] - 'a'].size() == 0)
    {
      cout << -1 << endl;
      return 0;
    }
  i64 ans = -1, l = 0;
  for (i64 i = 0; i < tsize; i++)
  {
    i64 c = t[i] - 'a';
    i64 it = upper_bound(pos[c].begin(), pos[c].end(), ans) - pos[c].begin();
    if (it == (i64)pos[c].size())
    {
      ans = pos[c][0];
      l++;
    }
    else
      ans = pos[c][it];
  }
  cout << l * ssize + ans + 1 << endl;
  return 0;
}
