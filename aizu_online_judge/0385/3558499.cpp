// URL: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3558499
// Date: Sat, 11 May 2019 14:19:13 +0900
// Language: C++14
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<i64> a(n);
  for (i64 i = 0; i < n; i++)
    cin >> a[i];
  i64 q;
  cin >> q;
  vector<pair<i64, i64>> xy(q);
  for (i64 i = 0; i < q; i++)
  {
    cin >> xy[i].first >> xy[i].second;
    xy[i].first--;
    xy[i].second--;
  }
  vector<i64> s = a;
  sort(s.begin(), s.end());
  i64 dif = 0;
  for (i64 i = 0; i < n; i++)
    if (a[i] != s[i])
      dif++;
  if (dif == 0)
  {
    cout << 0 << endl;
    return 0;
  }
  for (i64 i = 0; i < q; i++)
  {
    i64 now[2] = {a[xy[i].first], a[xy[i].second]}, aft[2] = {s[xy[i].first], s[xy[i].second]};
    i64 d = (now[1] == aft[0]) + (now[0] == aft[1]) - (now[0] == aft[0]) - (now[1] == aft[1]);
    dif -= d;
    if (dif == 0)
    {
      cout << i + 1 << endl;
      return 0;
    }
    swap(a[xy[i].first], a[xy[i].second]);
  }
  cout << -1 << endl;
  return 0;
}
