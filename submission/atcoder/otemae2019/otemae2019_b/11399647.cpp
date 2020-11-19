// URL: https://atcoder.jp/contests/otemae2019/submissions/11399647
// Date: Wed, 01 Apr 2020 00:24:31 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 M, N, K;
  cin >> M >> N >> K;
  vector<i64> x(N);
  for (i64 i = 0; i < N; i++)
    cin >> x[i];
  i64 ans = 0;
  for (i64 i = 1; i <= M; i++)
  {
    set<i64> s;
    i64 cnt = 0;
    for (i64 j = 0; j < N; j++)
      if (i == x[j])
        cnt++;
      else if (abs(i - x[j]) <= K)
        s.insert(abs(i - x[j]));
    ans = max(ans, cnt + (i64)s.size());
  }
  cout << ans << endl;
  return 0;
}
