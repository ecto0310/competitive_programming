// URL: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=4241485
// Date: Sat, 07 Mar 2020 16:58:21 +0900
// Language: C++14
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 N, M, C;
  cin >> N >> M >> C;
  vector<i64> l(C);
  for (i64 i = 0; i < C; i++)
    cin >> l[i];
  vector<pair<i64, i64>> b(N);
  for (i64 i = 0; i < N; i++)
  {
    cin >> b[i].second >> b[i].first;
    b[i].second--;
  }
  sort(b.rbegin(), b.rend());
  i64 ans = 0, cnt = 0;
  for (pair<i64, i64> i : b)
  {
    if (0 < l[i.second])
    {
      ans += i.first;
      l[i.second]--;
      cnt++;
    }
    if (M <= cnt)
      break;
  }
  cout << ans << endl;
  return 0;
}
