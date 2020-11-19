// URL: https://atcoder.jp/contests/abc150/submissions/9491953
// Date: Mon, 13 Jan 2020 15:09:25 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  string s;
  cin >> n >> s;
  i64 ans = 0;
  for (i64 i = 0; i < n - 2; i++)
    if (s.substr(i, 3) == "ABC")
      ans++;
  cout << ans << endl;
  return 0;
}
