// URL: https://atcoder.jp/contests/iroha2019-day1/submissions/5196137
// Date: Tue, 30 Apr 2019 13:36:00 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, a, b;
  cin >> n >> a >> b;
  vector<i64> d(b);
  for (i64 i = 0; i < b; i++)
    cin >> d[i];
  d.push_back(n + 1);
  sort(d.begin(), d.end());
  i64 ans = n - b - (b != 0 ? (d[0] - 1) / a : n / a);
  for (i64 i = 1; i < b + 1; i++)
    ans -= (d[i] - d[i - 1] - 1) / a;
  cout << ans << endl;
  return 0;
}
