// URL: https://atcoder.jp/contests/abc165/submissions/12603644
// Date: Sat, 02 May 2020 21:31:54 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

struct Point
{
  i64 a, b, c, d;
};

i64 N, M, Q;
vector<Point> t;

i64 dfs(i64 s, i64 b, vector<i64> now)
{
  i64 ret = 0;
  if (s == N)
  {
    for (i64 i = 0; i < Q; i++)
      if (now[t[i].b] - now[t[i].a] == t[i].c)
        ret += t[i].d;
    return ret;
  }
  now.push_back(0);
  for (i64 i = b; i <= M; i++)
  {
    now[s] = i;
    ret = max(ret, dfs(s + 1, i, now));
  }
  return ret;
}

int main()
{
  cin >> N >> M >> Q;
  t.resize(Q);
  for (i64 i = 0; i < Q; i++)
  {
    i64 a, b, c, d;
    cin >> a >> b >> c >> d;
    a--;
    b--;
    t[i] = {a, b, c, d};
  }
  cout << dfs(0, 1, vector<i64>()) << endl;
  return 0;
}
