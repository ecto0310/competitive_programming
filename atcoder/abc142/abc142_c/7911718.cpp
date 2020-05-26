// URL: https://atcoder.jp/contests/abc142/submissions/7911718
// Date: Wed, 09 Oct 2019 01:08:02 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<i64> ans(n);
  for (i64 i = 0; i < n; i++)
  {
    i64 a;
    cin >> a;
    ans[a - 1] = i + 1;
  }
  for (i64 i = 0; i < n; i++)
    cout << ans[i] << (i + 1 == n ? "\n" : " ");
  return 0;
}
