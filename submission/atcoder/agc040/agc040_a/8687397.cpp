// URL: https://atcoder.jp/contests/agc040/submissions/8687397
// Date: Thu, 28 Nov 2019 21:59:52 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  string s;
  cin >> s;
  i64 n = s.size() + 1;
  vector<i64> a(n, 0);
  for (i64 i = 0; i < n - 1; i++)
    if (s[i] == '<')
      a[i + 1] = max(a[i + 1], a[i] + 1);
  for (i64 i = n - 2; 0 <= i; i--)
    if (s[i] == '>')
      a[i] = max(a[i], a[i + 1] + 1);
  i64 ans = 0;
  for (i64 i = 0; i < n; i++)
    ans += a[i];
  cout << ans << endl;
  return 0;
}
