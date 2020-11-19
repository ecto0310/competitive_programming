// URL: https://atcoder.jp/contests/abc147/submissions/8889432
// Date: Tue, 10 Dec 2019 00:21:46 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  string s;
  cin >> s;
  i64 ans = 0;
  for (i64 i = 0; i < s.size() / 2; i++)
    if (s[i] != s[s.size() - i - 1])
      ans++;
  cout << ans << endl;
  return 0;
}
