// URL: https://atcoder.jp/contests/pakencamp-2018-day2/submissions/3860917
// Date: Mon, 24 Dec 2018 13:17:31 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int n, d;
  cin >> n >> d;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a.begin(), a.end(), greater<int>());
  int ans = 0;
  for (int i = d - 1; i < n; i += d)
    ans += a[i];
  cout << ans << endl;

  return 0;
}
