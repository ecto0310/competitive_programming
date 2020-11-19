// URL: https://atcoder.jp/contests/abc157/submissions/10479101
// Date: Mon, 02 Mar 2020 08:30:24 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 N, M;
  cin >> N >> M;
  vector<i64> s(M), c(M);
  for (i64 i = 0; i < M; i++)
    cin >> s[i] >> c[i];
  for (i64 i = (N == 1 ? 0 : pow(10, N - 1)); i < pow(10, N); i++)
  {
    string num = to_string(i);
    bool ok = true;
    for (i64 i = 0; i < M; i++)
      if (num[s[i] - 1] - '0' != c[i])
        ok = false;
    if (ok)
    {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
