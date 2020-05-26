// URL: https://atcoder.jp/contests/ddcc2017-final/submissions/7920493
// Date: Wed, 09 Oct 2019 22:57:35 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, z;
  cin >> n >> z;
  vector<i64> a(n);
  for (i64 i = 0; i < n; i++)
    cin >> a[i];
  for (i64 i = 0; i < n; i++)
    a[i] = __gcd(a[i], z);
  i64 ans = a[0];
  for (i64 i = 1; i < n; i++)
    ans = ans / __gcd(ans, a[i]) * a[i];
  cout << ans << endl;
  return 0;
}
