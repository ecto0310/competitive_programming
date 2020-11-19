// URL: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3729645
// Date: Tue, 09 Jul 2019 16:00:35 +0900
// Language: C++14
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

bool check(vector<string> &v, i64 n, i64 x, i64 y)
{
  return (v[x][y] == v[n - x - 1][y] && v[x][y] == v[x][n - y - 1] && v[x][y] == v[n - x - 1][n - y - 1]);
}

int main()
{
  i64 c, n;
  cin >> c >> n;
  vector<string> p(n);
  for (i64 i = 0; i < n; i++)
    cin >> p[i];
  i64 def = 0;
  vector<vector<bool>> ok(n, vector<bool>(n));
  for (i64 i = 0; i < n / 2; i++)
    for (i64 j = 0; j < n / 2; j++)
      if (check(p, n, i, j))
        ok[i][j] = true;
      else
      {
        ok[i][j] = false;
        def++;
      }
  i64 ans = (def == 0 ? 1 : 0);
  for (i64 i = 0; i < c - 1; i++)
  {
    i64 d;
    cin >> d;
    vector<i64> pr(d), pc(d);
    for (i64 j = 0; j < d; j++)
    {
      cin >> pr[j] >> pc[j];
      pr[j]--;
      pc[j]--;
    }
    for (i64 j = 0; j < d; j++)
    {
      p[pr[j]][pc[j]] = (p[pr[j]][pc[j]] == '1' ? '0' : '1');
      if (n / 2 <= pr[j])
        pr[j] = n - 1 - pr[j];
      if (n / 2 <= pc[j])
        pc[j] = n - 1 - pc[j];
      bool s = check(p, n, pr[j], pc[j]);
      if (s != ok[pr[j]][pc[j]])
      {
        if (s)
          def--;
        else
          def++;
      }
      ok[pr[j]][pc[j]] = s;
    }
    if (def == 0)
      ans++;
  }
  cout << ans << endl;
  return 0;
}
