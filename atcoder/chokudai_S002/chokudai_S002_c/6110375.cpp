// URL: https://atcoder.jp/contests/chokudai_S002/submissions/6110375
// Date: Mon, 24 Jun 2019 15:05:00 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  i64 ans = 0;
  for (i64 i = 0; i < n; i++)
  {
    i64 a, b;
    cin >> a >> b;
    ans = max(ans, a + b);
  }
  cout << ans << endl;
  return 0;
}
