// URL: https://atcoder.jp/contests/arc072/submissions/5437466
// Date: Sat, 18 May 2019 21:12:50 +0900
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
  i64 ans[2] = {}, sum[2] = {};
  for (i64 i = 0; i < n; i++)
    if (i % 2 == 0)
    {
      sum[0] += a[i];
      if (sum[0] < 1)
      {
        ans[0] += -sum[0] + 1;
        sum[0] = 1;
      }
      sum[1] += a[i];
      if (-1 < sum[1])
      {
        ans[1] += sum[1] + 1;
        sum[1] = -1;
      }
    }
    else
    {
      sum[0] += a[i];
      if (-1 < sum[0])
      {
        ans[0] += sum[0] + 1;
        sum[0] = -1;
      }
      sum[1] += a[i];
      if (sum[1] < 1)
      {
        ans[1] += -sum[1] + 1;
        sum[1] = 1;
      }
    }
  cout << min(ans[0], ans[1]) << endl;
  return 0;
}
