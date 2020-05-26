// URL: https://atcoder.jp/contests/code-thanks-festival-2017-open/submissions/6110218
// Date: Mon, 24 Jun 2019 23:52:02 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, k;
  cin >> n >> k;
  priority_queue<pair<i64, i64>, vector<pair<i64, i64>>, greater<pair<i64, i64>>> pque;
  for (i64 i = 0; i < n; i++)
  {
    i64 a, b;
    cin >> a >> b;
    pque.push({a, b});
  }
  i64 ans = 0;
  for (i64 i = 0; i < k; i++)
  {
    pair<i64, i64> p = pque.top();
    pque.pop();
    ans += p.first;
    p.first += p.second;
    pque.push(p);
  }
  cout << ans << endl;
  return 0;
}
