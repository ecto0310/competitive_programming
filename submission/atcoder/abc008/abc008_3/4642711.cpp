// URL: https://atcoder.jp/contests/abc008/submissions/4642711
// Date: Wed, 20 Mar 2019 23:21:57 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> c(n);
  for (int i = 0; i < n; i++)
    cin >> c[i];
  double ans = 0;
  for (int i = 0; i < n; i++)
  {
    int cnt = 0;
    for (int j = 0; j < n; j++)
      if (i != j && c[i] % c[j] == 0)
        cnt++;
    if (cnt % 2 == 0)
      ans += ((cnt + 1) / 2 + 1) / (double)(cnt + 1);
    else
      ans += 0.5;
  }
  cout << fixed << setprecision(7) << ans << endl;

  return 0;
}
