// URL: https://atcoder.jp/contests/ddcc2020-qual/submissions/8589538
// Date: Sat, 23 Nov 2019 23:43:00 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 m;
  cin >> m;
  vector<pair<i64, i64>> d(m);
  for (i64 i = 0; i < m; i++)
    cin >> d[i].first >> d[i].second;
  i64 sum = 0, sumc = 0;
  for (i64 i = 0; i < m; i++)
  {
    sum += d[i].first * d[i].second;
    sumc += d[i].second;
  }
  cout << (sumc - 1) + (sum - 1) / 9 << endl;
  return 0;
}
