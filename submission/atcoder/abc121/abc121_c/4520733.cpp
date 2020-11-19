// URL: https://atcoder.jp/contests/abc121/submissions/4520733
// Date: Sat, 09 Mar 2019 21:21:14 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int N, M;
  cin >> N >> M;
  vector<pair<long long, long long>> D(N);
  for (int i = 0; i < N; i++)
    cin >> D[i].first >> D[i].second;
  sort(D.begin(), D.end());
  long long ans = 0, cnt = 0;
  for (pair<long long, long long> t : D)
  {
    if (cnt + t.second < M)
      ans += t.first * t.second;
    else
    {
      ans += t.first * max(0LL, (M - cnt));
      break;
    }
    cnt += t.second;
  }
  cout << ans << endl;

  return 0;
}
