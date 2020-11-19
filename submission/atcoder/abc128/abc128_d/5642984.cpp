// URL: https://atcoder.jp/contests/abc128/submissions/5642984
// Date: Sun, 26 May 2019 21:34:49 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, k;
  cin >> n >> k;
  vector<i64> v(n);
  for (i64 i = 0; i < n; i++)
    cin >> v[i];
  i64 ans = 0;
  for (i64 i = 0; i <= n; i++)
    for (i64 j = 0; j <= n - i; j++)
      if (i + j <= k)
      {
        priority_queue<i64, vector<i64>, greater<i64>> que;
        i64 sum = 0;
        for (i64 l = 0; l < i; l++)
        {
          que.push(v[l]);
          sum += v[l];
        }
        for (i64 l = 0; l < j; l++)
        {
          que.push(v[n - l - 1]);
          sum += v[n - l - 1];
        }
        for (i64 l = 0; l < k - i - j; l++)
          if (que.size() == 0)
            break;
          else if (que.top() < 0)
          {
            sum -= que.top();
            que.pop();
          }
        ans = max(ans, sum);
      }
  cout << ans << endl;
  return 0;
}
