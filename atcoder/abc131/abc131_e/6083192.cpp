// URL: https://atcoder.jp/contests/abc131/submissions/6083192
// Date: Sat, 22 Jun 2019 23:01:24 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, k;
  cin >> n >> k;
  if ((n - 1) * (n - 2) / 2 < k)
  {
    cout << -1 << endl;
    return 0;
  }
  cout << n - 1 + (n - 1) * (n - 2) / 2 - k << endl;
  for (i64 i = 2; i <= n; i++)
    cout << 1 << " " << i << endl;
  i64 cnt = 0;
  for (i64 i = 2; i <= n; i++)
    for (i64 j = i + 1; j <= n; j++)
    {
      if (cnt == (n - 1) * (n - 2) / 2 - k)
        return 0;
      cout << i << " " << j << endl;
      cnt++;
    }
  return 0;
}
