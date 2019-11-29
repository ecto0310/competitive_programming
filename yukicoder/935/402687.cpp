// URL: https://yukicoder.me/submissions/402687
// Date: Fri, 29 Nov 2019 22:42:34 +0900
// Language: C++14
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  string s;
  cin >> n >> s;
  vector<i64> a(n);
  for (i64 i = 0; i < n; i++)
    cin >> a[i];
  i64 q;
  cin >> q;
  vector<i64> en(n + 1);
  for (i64 i = 0; i < n; i++)
  {
    en[i + 1] = en[i];
    if (s[i] == 'E')
      en[i + 1] += 1;
  }
  for (i64 i = 0; i < q; i++)
  {
    i64 k;
    cin >> k;
    i64 ans = 0, sum = 0, right = 0;
    for (i64 left = 0; left < n; left++)
    {
      while (right < n && sum + a[right] <= k)
      {
        sum += a[right];
        right++;
      }
      ans = max(ans, en[right] - en[left]);
      if (right == left)
        right++;
      else
        sum -= a[left];
    }
    cout << ans << endl;
  }
  return 0;
}
