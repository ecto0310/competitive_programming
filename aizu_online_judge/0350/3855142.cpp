// URL: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3855142
// Date: Mon, 09 Sep 2019 16:17:20 +0900
// Language: C++14
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  string s;
  cin >> s;
  i64 p, l, r;
  l = s.size();
  r = s.size() + 1;
  string n, m;
  for (i64 i = 0; i < s.size(); i++)
    if (s[i] == '.')
      p = i;
    else if (s[i] == '(')
    {
      l = i;
      m = n;
    }
    else if (s[i] == ')')
      r = i;
    else
      n += s[i];
  i64 ans[2];
  if (r - l - 1 == 0)
  {
    ans[0] = stoi(n);
    ans[1] = pow(10, l - p - 1);
  }
  else
  {
    ans[0] = stoi(n) - stoi(m);
    ans[1] = pow(10, l - p - 1 + r - l - 1) - pow(10, l - p - 1);
  }
  i64 g = __gcd(ans[0], ans[1]);
  cout << ans[0] / g << "/" << ans[1] / g << endl;
  return 0;
}
