// URL: https://atcoder.jp/contests/abc181/submissions/17826603
// Date: Mon, 02 Nov 2020 01:19:22 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, k=3;
  cin >> n;
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
    cout << "Yes" << endl;
    return 0;
  }
  map<i64, i64> cntx;
  for (i64 i = 0; i < n; i++)
    cntx[x[i]]++;
  for (pair<i64, i64> i : cntx)
    if (k <= i.second)
    {
      cout << "Yes" << endl;
      return 0;
    }
  cout << "No" << endl;
  return 0;
}
