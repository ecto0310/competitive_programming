// URL: https://atcoder.jp/contests/abc143/submissions/8021656
// Date: Sat, 19 Oct 2019 21:02:57 +0900
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
  i64 ans = 0;
  for (i64 i = 0; i < n; i++)
    for (i64 j = i + 1; j < n; j++)
      ans += d[i] * d[j];
  cout << ans << endl;
  return 0;
}
