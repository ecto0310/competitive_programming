// URL: https://atcoder.jp/contests/dwacon6th-prelims/submissions/9419498
// Date: Sat, 11 Jan 2020 20:02:38 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<string> s(n);
  vector<i64> t(n);
  for (i64 i = 0; i < n; i++)
    cin >> s[i] >> t[i];
  string x;
  cin >> x;
  i64 ans = 0;
  bool ok = false;
  for (i64 i = 0; i < n; i++)
    if (ok)
      ans += t[i];
    else if (s[i] == x)
      ok = true;
  cout << ans << endl;

  return 0;
}
