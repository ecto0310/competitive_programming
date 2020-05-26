// URL: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3856567
// Date: Tue, 10 Sep 2019 00:42:57 +0900
// Language: C++14
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, k;
  cin >> n >> k;
  vector<i64> x(n), y(n);
  for (i64 i = 0; i < n; i++)
    cin >> x[i] >> y[i];
  vector<pair<double, double>> cnt;
  for (i64 i = 0; i < n; i++)
    for (i64 j = i + 1; j < n; j++)
      if (x[i] != x[j])
      {
        double t = (double)(y[i] - y[j]) / (x[i] - x[j]);
        double s = (double)(x[i] * y[j] - x[j] * y[i]) / (x[i] - x[j]);
        cnt.push_back({t, s});
      }
  sort(cnt.begin(), cnt.end());
  i64 size = cnt.size();
  i64 c = 1, m = 1;
  for (i64 i = 1; i < size; i++)
    if (cnt[i] == cnt[i - 1])
    {
      c++;
    }
    else
    {
      m = max(m, c);
      c = 1;
    }
  if (k * (k - 1) / 2 <= max(m, c))
  {
    cout << 1 << endl;
    return 0;
  }
  map<i64, i64> cntx;
  for (i64 i = 0; i < n; i++)
    cntx[x[i]]++;
  for (pair<i64, i64> i : cntx)
    if (k <= i.second)
    {
      cout << 1 << endl;
      return 0;
    }
  cout << 0 << endl;
  return 0;
}
