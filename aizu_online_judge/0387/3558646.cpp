// URL: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3558646
// Date: Sat, 11 May 2019 14:54:58 +0900
// Language: C++14
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;
const i64 MOD = 1e9 + 7;

int main()
{
  i64 n;
  cin >> n;
  vector<vector<i64>> s(n);
  for (i64 i = 0; i < n; i++)
  {
    i64 m;
    cin >> m;
    s[i].resize(m);
    for (i64 j = 0; j < m; j++)
      cin >> s[i][j];
  }
  priority_queue<i64> que;
  i64 ans = 0;
  for (i64 i = n - 1; 0 <= i; i--)
  {
    i64 size = s[i].size();
    for (i64 j = 0; j < size; j++)
      que.push(s[i][j]);
    ans += que.top();
    que.pop();
  }
  cout << ans << endl;
  return 0;
}
