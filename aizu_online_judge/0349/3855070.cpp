// URL: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3855070
// Date: Mon, 09 Sep 2019 15:53:52 +0900
// Language: C++14
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

vector<i64> edge, cnt;
set<i64> s;

i64 dfs(i64 now)
{
  if (2 <= cnt[now] || cnt[now] == -1)
    return 0;
  cnt[now]++;
  s.insert(now);
  dfs(edge[now]);
  return 0;
}

int main()
{
  i64 n;
  cin >> n;
  edge.resize(n);
  for (i64 i = 0; i < n; i++)
  {
    i64 a;
    cin >> a;
    edge[i] = (i + a) % n;
  }
  cnt.resize(n);
  for (i64 i = 0; i < n; i++)
  {
    if (cnt[i] == 0)
      dfs(i);
    for (i64 j : s)
      if (cnt[j] == 1)
        cnt[j] = -1;
    s.clear();
  }
  i64 ans = 0;
  for (i64 i = 0; i < n; i++)
    if (2 <= cnt[i])
      ans++;
  cout << ans << endl;
  return 0;
}
