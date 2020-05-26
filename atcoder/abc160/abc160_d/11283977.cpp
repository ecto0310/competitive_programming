// URL: https://atcoder.jp/contests/abc160/submissions/11283977
// Date: Sat, 28 Mar 2020 21:13:58 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N, X, Y;
  cin >> N >> X >> Y;
  vector<i64> ans(N);
  vector<i64> edge[N];
  for (i64 i = 0; i < N - 1; i++)
  {
    edge[i].push_back(i + 1);
    edge[i + 1].push_back(i);
  }
  X--;
  Y--;
  edge[X].push_back(Y);
  edge[Y].push_back(X);
  for (i64 i = 0; i < N; i++)
  {
    vector<i64> far(N, 1e9);
    queue<i64> que;
    far[i] = 0;
    que.push(i);
    while (que.size())
    {
      i64 p = que.front();
      que.pop();
      for (i64 j : edge[p])
        if (far[p] + 1 < far[j])
        {
          far[j] = far[p] + 1;
          ans[far[j] - 1]++;
          que.push(j);
        }
    }
  }
  for (i64 i = 0; i < N - 1; i++)
    cout << ans[i] / 2 << endl;
  return 0;
}
