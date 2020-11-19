// URL: https://codeforces.com/contest/1195/submission/57204492
// Date: Wed, 17 Jul 2019 23:42:21 +0900
// Language: GNU C++14
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, k;
  cin >> n >> k;
  vector<i64> cnt(k);
  for (i64 i = 0; i < n; i++)
  {
    i64 a;
    cin >> a;
    a--;
    cnt[a]++;
  }
  i64 ans = 0, h = 0;
  for (i64 i = 0; i < k; i++)
    if (cnt[i] % 2 == 0)
      ans += cnt[i];
    else
    {
      ans += cnt[i] / 2 * 2;
      if (h == 0)
        h = 1;
      else
      {
        h = 0;
        ans++;
      }
    }
  if (h == 1)
    ans++;
  cout << ans << endl;
  return 0;
}
