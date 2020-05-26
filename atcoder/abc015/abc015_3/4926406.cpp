// URL: https://atcoder.jp/contests/abc015/submissions/4926406
// Date: Fri, 12 Apr 2019 18:14:56 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

i64 n, k;
vector<vector<i64>> t;

bool dfs(i64 now, i64 val)
{
  if (now == n)
    return val == 0;
  for (i64 i = 0; i < k; i++)
    if (dfs(now + 1, val ^ t[now][i]))
      return true;
  return false;
}

int main()
{
  cin >> n >> k;
  t = vector<vector<i64>>(n, vector<i64>(k));
  for (i64 i = 0; i < n; i++)
    for (i64 j = 0; j < k; j++)
      cin >> t[i][j];
  if (dfs(0, 0))
    cout << "Found" << endl;
  else
    cout << "Nothing" << endl;

  return 0;
}
