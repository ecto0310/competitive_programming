// URL: https://atcoder.jp/contests/agc027/submissions/3203013
// Date: Sat, 15 Sep 2018 22:10:35 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a.begin(), a.end());
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    x -= a[i];
    cerr << x << endl;
    if (x >= 0)
      ans = i + 1;
    else
    {
      cout << ans << endl;
      return 0;
    }
  }
  cout << (0 < x ? ans - 1 : ans) << endl;

  return 0;
}
