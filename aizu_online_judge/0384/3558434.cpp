// URL: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3558434
// Date: Sat, 11 May 2019 14:04:31 +0900
// Language: C++14
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 a, n, m;
  cin >> a >> n >> m;
  i64 ans = 0;
  for (i64 i = 1; i <= sqrt(m); i++)
  {
    i64 p = 1;
    for (i64 j = 0; j < n; j++)
      p *= i;
    if (m < p)
      break;
    string s = to_string(p);
    i64 sum = 0;
    for (i64 j = 0; j < s.size(); j++)
      sum += s[j] - '0';
    if (sum + a == i)
      ans++;
  }
  cout << ans << endl;
  return 0;
}
