// URL: https://atcoder.jp/contests/iroha2019-day1/submissions/5196496
// Date: Tue, 30 Apr 2019 13:44:54 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, k;
  cin >> n >> k;
  vector<i64> ans;
  i64 now = 2;
  while (now * now <= n)
    if (ans.size() + 1 == k)
      break;
    else if (n % now == 0)
    {
      ans.push_back(now);
      n /= now;
    }
    else
      now++;
  if (n != 1)
    ans.push_back(n);
  if (ans.size() != k)
    cout << -1;
  else
    for (i64 i = 0; i < k; i++)
      cout << ans[i] << (i + 1 == k ? "" : " ");
  cout << endl;
  return 0;
}
