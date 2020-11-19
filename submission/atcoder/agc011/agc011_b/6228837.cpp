// URL: https://atcoder.jp/contests/agc011/submissions/6228837
// Date: Wed, 03 Jul 2019 23:58:07 +0900
// Language: C++14 (GCC 5.4.1)
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
  sort(a.begin(), a.end());
  vector<i64> sum(n);
  sum[0] = a[0];
  for (i64 i = 1; i < n; i++)
    sum[i] = sum[i - 1] + a[i];
  for (i64 i = n - 2; 0 <= i; i--)
  {
    if (sum[i] * 2 < a[i + 1])
    {
      cout << n - i - 1 << endl;
      return 0;
    }
  }
  cout << n << endl;
  return 0;
}
