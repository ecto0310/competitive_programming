// URL: https://atcoder.jp/contests/abc065/submissions/3234286
// Date: Fri, 21 Sep 2018 16:01:58 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  long long ans = 1;
  for (int i = n; i > 0; i--)
    ans = ans * i % 1000000007;
  for (int i = m; i > 0; i--)
    ans = ans * i % 1000000007;
  if (abs(n - m) >= 2)
    cout << 0 << endl;
  else if (n == m)
    cout << ans * 2 % 1000000007 << endl;
  else
    cout << ans << endl;

  return 0;
}
