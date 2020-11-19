// URL: https://atcoder.jp/contests/abc128/submissions/5636684
// Date: Sun, 26 May 2019 21:06:04 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<pair<string, pair<i64, i64>>> d(n);
  for (i64 i = 0; i < n; i++)
  {
    cin >> d[i].first >> d[i].second.first;
    d[i].second.second = i + 1;
  }
  sort(d.begin(), d.end(), [](const pair<string, pair<i64, i64>> &x, const pair<string, pair<i64, i64>> &y) {
    return (x.first == y.first ? x.second.first > y.second.first : x.first < y.first);
  });
  for (i64 i = 0; i < n; i++)
    cout << d[i].second.second << endl;
  return 0;
}
