// URL: https://atcoder.jp/contests/agc034/submissions/5768466
// Date: Sun, 02 Jun 2019 23:41:45 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, a, b, c, d;
  string s;
  cin >> n >> a >> b >> c >> d >> s;
  s = "#" + s + "#";
  bool ok = true, pass = false;
  for (i64 i = a; i < c; i++)
    if (s.substr(i, 2) == "##")
      ok = false;
  for (i64 i = b; i < d; i++)
    if (s.substr(i, 2) == "##")
      ok = false;
  for (i64 i = b; i <= d; i++)
    if (s.substr(i - 1, 3) == "...")
      pass = true;
  if (ok && (d < c ? pass : true))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
