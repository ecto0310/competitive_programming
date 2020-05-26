// URL: https://atcoder.jp/contests/agc020/submissions/3872482
// Date: Tue, 25 Dec 2018 22:04:53 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int k;
  cin >> k;
  vector<long long> a(k);
  for (int i = 0; i < k; i++)
    cin >> a[i];
  long long l = 2, r = 2;
  for (int i = k - 1; - 1 < i; i--)
  {
    l = (l + a[i] - 1) / a[i] * a[i];
    r = r / a[i] * a[i] + a[i] - 1;
  }
  if (r < l)
    cout << -1 << endl;
  else
    cout << l << " " << r << endl;

  return 0;
}
