// URL: https://atcoder.jp/contests/joi2016ho/submissions/4120159
// Date: Tue, 29 Jan 2019 14:54:20 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int N, M, K;
vector<int> A;
vector<long long> memo;

long long dfs(int pos)
{
  if (pos == N)
    return 0;
  if (memo[pos] != -1)
    return memo[pos];
  long long ret = 1e18;
  int mi = 1e9, ma = 0;
  for (int i = pos; i < min(N, pos + M); i++)
  {
    mi = min(mi, A[i]);
    ma = max(ma, A[i]);
    ret = min(ret, dfs(i + 1) + K + (long long)(i - pos + 1) * (ma - mi));
  }
  return memo[pos] = ret;
}

int main()
{
  cin >> N >> M >> K;
  A.resize(N);
  for (int i = 0; i < N; i++)
    cin >> A[i];
  memo.resize(N, -1);
  cout << dfs(0) << endl;

  return 0;
}
