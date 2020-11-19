// URL: https://atcoder.jp/contests/iroha2019-day1/submissions/5195528
// Date: Tue, 30 Apr 2019 13:20:45 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, x, y;
  cin >> n >> x >> y;
  vector<i64> a(n);
  for (i64 i = 0; i < n; i++)
    cin >> a[i];
  sort(a.begin(), a.end(), greater<i64>());
  for (i64 i = 0; i < n; i++)
    if (i % 2 == 0)
      x += a[i];
    else
      y += a[i];
  if (x == y)
    cout << "Draw" << endl;
  else if (x < y)
    cout << "Aoki" << endl;
  else
    cout << "Takahashi" << endl;
  return 0;
}
