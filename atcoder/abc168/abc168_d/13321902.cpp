// URL: https://atcoder.jp/contests/abc168/submissions/13321902
// Date: Sun, 17 May 2020 12:34:16 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "
"

int main()
{
  i64 N, M;
  cin >> N >> M;
  vector<i64> edge[N];
  for (i64 i = 0; i < M; i++)
  {
    i64 A, B;
    cin >> A >> B;
    A--;
    B--;
    edge[A].push_back(B);
    edge[B].push_back(A);
  }
  vector<i64> far(N, 1e9), ans(N);
  queue<i64> que;
  far[0] = 0;
  que.push(0);
  while (que.size())
  {
    i64 p = que.front();
    que.pop();
    for (i64 i : edge[p])
      if (far[p] + 1 < far[i])
      {
        far[i] = far[p] + 1;
        ans[i] = p;
        que.push(i);
      }
  }
  bool ok = true;
  for (i64 i = 0; i < N; i++)
    if (far[i] == 1e9)
      ok = false;
  if (!ok)
  {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  for (i64 i = 1; i < N; i++)
    cout << ans[i] + 1 << endl;
  return 0;
}
