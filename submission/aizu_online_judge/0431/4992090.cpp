// URL: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=4992090
// Date: Sat, 14 Nov 2020 22:17:20 +0900
// Language: C++14
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N;
  cin >> N;
  vector<i64> r(N);
  for (i64 i = 0; i < N; i++)
    cin >> r[i];
  i64 ans = 0, m = 0;
  for (i64 i = r.size() - 1; 0 <= i; i--)
    if (m < r[i])
    {
      ans++;
      m = r[i];
    }
  cout << ans << endl;
  return 0;
}
