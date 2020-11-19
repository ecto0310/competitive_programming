// URL: https://atcoder.jp/contests/abc059/submissions/3922005
// Date: Thu, 03 Jan 2019 19:37:27 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  long long ans[2] = {}, sum[2] = {};
  for (int i = 0; i < n; i++)
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
