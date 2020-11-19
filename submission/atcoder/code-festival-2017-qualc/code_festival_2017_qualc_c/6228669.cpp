// URL: https://atcoder.jp/contests/code-festival-2017-qualc/submissions/6228669
// Date: Wed, 03 Jul 2019 23:43:26 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  string s;
  cin >> s;
  i64 l = 0, r = s.size() - 1;
  i64 ans = 0;
  while (0 < r - l)
  {
    if (s[l] == s[r])
    {
      l++;
      r--;
    }
    else if (s[l] == 'x')
    {
      l++;
      ans++;
    }
    else if (s[r] == 'x')
    {
      r--;
      ans++;
    }
    else
    {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << ans << endl;
  return 0;
}
