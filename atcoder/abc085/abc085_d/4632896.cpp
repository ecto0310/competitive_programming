// URL: https://atcoder.jp/contests/abc085/submissions/4632896
// Date: Tue, 19 Mar 2019 20:53:32 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

const int MOD = 1e9 + 7;

int main()
{
  int n, h;
  cin >> n >> h;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++)
    cin >> a[i] >> b[i];
  int ans = 0, damage = 0;
  int maxa = *max_element(a.begin(), a.end());
  sort(b.begin(), b.end(), greater<int>());
  for (int i = 0; i < n; i++)
  {
    if (maxa <= b[i])
    {
      ans++;
      damage += b[i];
    }
    else
      break;
    if (h <= damage)
      break;
  }
  if (damage < h)
    ans += (h - damage + maxa - 1) / maxa;
  cout << ans << endl;

  return 0;
}
