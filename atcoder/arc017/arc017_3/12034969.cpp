// URL: https://atcoder.jp/contests/arc017/submissions/12034969
// Date: Sat, 18 Apr 2020 15:50:07 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

map<i64, i64> cnt(vector<i64> x)
{
  map<i64, i64> ret;
  i64 n = x.size();
  for (i64 i = 0; i < (1 << n); i++)
  {
    i64 sum = 0;
    for (i64 j = 0; j < n; j++)
      if (i & (1 << j))
        sum += x[j];
    ret[sum]++;
  }
  return ret;
}

int main()
{
  i64 N, X;
  cin >> N >> X;
  vector<i64> w1((N + 1) / 2), w2(N / 2);
  for (i64 i = 0; i < N; i++)
    if (i % 2 == 0)
      cin >> w1[i / 2];
    else
      cin >> w2[i / 2];
  map<i64, i64> f = cnt(w1), s = cnt(w2);
  i64 ans = 0;
  for (auto i : f)
    ans += i.second * s[X - i.first];
  cout << ans << endl;
  return 0;
}
