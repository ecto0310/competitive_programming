// URL: https://atcoder.jp/contests/joi2020yo1a/submissions/10402676
// Date: Sat, 29 Feb 2020 17:43:03 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  string s;
  cin >> n >> s;
  i64 ans = 0;
  for (i64 i = 0; i < n; i++)
    if (s[i] == 'a' || s[i] == 'i' || s[i] == 'u' || s[i] == 'e' || s[i] == 'o')
      ans++;
  cout << ans << endl;
  return 0;
}
