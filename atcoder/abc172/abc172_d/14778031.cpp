// URL: https://atcoder.jp/contests/abc172/submissions/14778031
// Date: Sat, 27 Jun 2020 22:47:41 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N;
  cin >> N;
  vector<i64> cnt(N + 1);
  for (i64 i = 1; i <= N; i++)
    for (i64 j = 1; i * j <= N; j++)
      cnt[i * j]++;
  i64 ans = 0;
  for (i64 i = 1; i <= N; i++)
    ans += cnt[i] * i;
  cout << ans << endl;
  return 0;
}
