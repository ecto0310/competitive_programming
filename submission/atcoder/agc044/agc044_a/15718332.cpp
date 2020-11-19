// URL: https://atcoder.jp/contests/agc044/submissions/15718332
// Date: Thu, 06 Aug 2020 15:01:03 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 T;
  cin >> T;
  for (i64 _ = 0; _ < T; _++)
  {
    i64 N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    i64 ans = 1e18;
    priority_queue<pair<i64, i64>, vector<pair<i64, i64>>, greater<pair<i64, i64>>> que;
    map<i64, i64> memo;
    que.push({0, N});
    i64 cost[6] = {0, 0, A, B, 0, C};
    while (que.size())
    {
      pair<i64, i64> p = que.top();
      que.pop();
      i64 v = p.first, n = p.second;
      if (ans <= v)
        break;
      if (n <= 1e18 / D)
        ans = min(ans, v + n * D);
      for (i64 i : {2, 3, 5})
      {
        i64 m = n % i;
        i64 v2 = v + m * D + cost[i];
        if (v2 < ans && (memo.count(n / i) == 0 || v2 < memo[n / i]))
        {
          que.push({v2, n / i});
          memo[n / i] = v2;
        }
        v2 = v + (i - m) * D + cost[i];
        if (v2 < ans && (memo.count(n / i + 1) == 0 || v2 < memo[n / i + 1]))
        {
          que.push({v2, n / i + 1});
          memo[n / i + 1] = v2;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
