// URL: https://atcoder.jp/contests/abc139/submissions/11156865
// Date: Mon, 23 Mar 2020 18:57:40 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

const i64 MOD = 998244353;

int main()
{
  i64 N;
  cin >> N;
  vector<pair<i64, i64>> xy(N);
  for (i64 i = 0; i < N; i++)
    cin >> xy[i].first >> xy[i].second;
  sort(xy.begin(), xy.end(), [](const pair<i64, i64> &l, const pair<i64, i64> &r) {
    return atan2(l.second, l.first) < atan2(r.second, r.first);
  });
  i64 ans = 0;
  for (i64 i = 0; i < N; i++)
    for (i64 j = 1; j <= N; j++)
    {
      i64 x = 0, y = 0;
      for (i64 k = 0; k < j; k++)
      {
        x += xy[(i + k) % N].first;
        y += xy[(i + k) % N].second;
      }
      ans = max(ans, x * x + y * y);
    }

  cout << fixed << setprecision(11) << sqrt(ans) << endl;
  return 0;
}
