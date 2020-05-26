// URL: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=4007693
// Date: Mon, 25 Nov 2019 23:21:38 +0900
// Language: C++14
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, m;
  cin >> n >> m;
  queue<i64> que[10];
  for (i64 _ = 0; _ < m; _++)
  {
    i64 s;
    cin >> s;
    if (s == 0)
    {
      i64 lane;
      cin >> lane;
      cout << que[lane - 1].front() << endl;
      que[lane - 1].pop();
    }
    else
    {
      i64 car;
      cin >> car;
      i64 p = 0, c = 1e9;
      for (i64 i = 0; i < n; i++)
        if (que[i].size() < c)
        {
          p = i;
          c = que[i].size();
        }
      que[p].push(car);
    }
  }
  return 0;
}
