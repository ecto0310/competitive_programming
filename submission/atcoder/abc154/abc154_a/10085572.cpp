// URL: https://atcoder.jp/contests/abc154/submissions/10085572
// Date: Fri, 14 Feb 2020 15:43:47 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  string s, t;
  i64 a, b;
  string u;
  cin >> s >> t >> a >> b >> u;
  if (s == u)
    a--;
  else
    b--;
  cout << a << " " << b << endl;
  return 0;
}
