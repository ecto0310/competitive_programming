// URL: https://atcoder.jp/contests/abc087/submissions/3336390
// Date: Fri, 05 Oct 2018 22:05:42 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int n, a[100][2];
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i][0];
  for (int i = 0; i < n; i++)
    cin >> a[i][1];
  int sum[100][2], ans = 0;
  sum[0][0] = a[0][0];
  sum[n - 1][1] = a[n - 1][1];
  for (int i = 1; i < n; i++)
    sum[i][0] = sum[i - 1][0] + a[i][0];
  for (int i = n - 2; i > -1; i--)
    sum[i][1] = sum[i + 1][1] + a[i][1];
  for (int i = 0; i < n; i++)
    ans = max(ans, sum[i][0] + sum[i][1]);
  cout << ans << endl;

  return 0;
}
