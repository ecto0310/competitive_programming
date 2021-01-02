// URL: https://atcoder.jp/contests/abc187/submissions/19170684
// Date: Sun, 03 Jan 2021 02:57:45 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N;
  cin >> N;
  vector<i64> A(N - 1), B(N - 1);
  vector<i64> edge[N];
  for (i64 i = 0; i < N - 1; i++)
  {
    cin >> A[i] >> B[i];
    A[i]--;
    B[i]--;
    edge[A[i]].push_back(B[i]);
    edge[B[i]].push_back(A[i]);
  }
  vector<i64> dep(N, -1);
  dep[0] = 0;
  vector<i64> q = {0};
  while (q.size())
  {
    i64 p = q.back();
    q.pop_back();
    for (i64 i : edge[p])
      if (dep[i] == -1)
      {
        dep[i] = dep[p] + 1;
        q.push_back(i);
      }
  }
  vector<i64> ans(N);
  i64 Q;
  cin >> Q;
  for (i64 _ = 0; _ < Q; _++)
  {
    i64 t, e, x;
    cin >> t >> e >> x;
    e--;
    i64 a = A[e], b = B[e];
    if (dep[b] < dep[a])
    {
      swap(a, b);
      t = (t == 1 ? 2 : 1);
    }
    if (t == 1)
    {
      ans[0] += x;
      ans[b] -= x;
    }
    else
    {
      ans[b] += x;
    }
  }
  q = {0};
  while (q.size())
  {
    i64 p = q.back();
    q.pop_back();
    for (i64 i : edge[p])
      if (dep[p] < dep[i])
      {
        ans[i] += ans[p];
        q.push_back(i);
      }
  }
  for (i64 i = 0; i < N; i++)
    cout << ans[i] << endl;
  return 0;
}
