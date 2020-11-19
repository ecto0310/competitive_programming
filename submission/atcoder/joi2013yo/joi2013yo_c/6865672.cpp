// URL: https://atcoder.jp/contests/joi2013yo/submissions/6865672
// Date: Mon, 12 Aug 2019 17:44:54 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  string name;
  cin >> n >> name;
  vector<string> s(n);
  for (i64 i = 0; i < n; i++)
    cin >> s[i];
  i64 ans = 0;
  for (i64 i = 0; i < n; i++)
  {
    bool ok = false;
    i64 size = s[i].size();
    for (i64 j = 0; j < size; j++)
      for (i64 k = 1; k < size; k++)
      {
        string t;
        for (i64 l = 0; j + k * l < size && l < (i64)name.size(); l++)
          t += s[i][j + k * l];
        if (name == t)
          ok = true;
      }
    if (ok)
      ans++;
  }
  cout << ans << endl;
  return 0;
}
