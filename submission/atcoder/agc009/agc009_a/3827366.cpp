// URL: https://atcoder.jp/contests/agc009/submissions/3827366
// Date: Thu, 20 Dec 2018 18:12:40 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<long long> a(n), b(n);
  for (int i = 0; i < n; i++)
    cin >> a[i] >> b[i];
  long long ans = 0;
  for (int i = n - 1; - 1 < i; i--)
    ans += ((a[i] + ans) % b[i] == 0 ? 0 : b[i]) - (a[i] + ans) % b[i];
  cout << ans << endl;

  return 0;
}
