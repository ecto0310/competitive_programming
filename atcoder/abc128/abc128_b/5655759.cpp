// URL: https://atcoder.jp/contests/abc128/submissions/5655759
// Date: Mon, 27 May 2019 01:12:39 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<pair<pair<string, i64>, i64>> d(n);
  for (i64 i = 0; i < n; i++)
  {
    cin >> d[i].first.first >> d[i].first.second;
    d[i].second = i + 1;
    d[i].first.second *= -1;
  }
  sort(d.begin(), d.end());
  for (i64 i = 0; i < n; i++)
    cout << d[i].second << endl;
  return 0;
}
