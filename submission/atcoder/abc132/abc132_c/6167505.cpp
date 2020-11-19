// URL: https://atcoder.jp/contests/abc132/submissions/6167505
// Date: Sat, 29 Jun 2019 21:14:38 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<i64> d(n);
  for (i64 i = 0; i < n; i++)
    cin >> d[i];
  sort(d.begin(), d.end());
  cout << d[n / 2] - d[n / 2 - 1] << endl;
  return 0;
}
