// URL: https://atcoder.jp/contests/keyence2020/submissions/9566709
// Date: Sat, 18 Jan 2020 21:16:25 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, k, s;
  cin >> n >> k >> s;
  for (i64 i = 0; i < k; i++)
    cout << s << (i + 1 == n ? "\n" : " ");
  for (i64 i = k; i < n; i++)
    if (s == 1e9)
      cout << 1 << (i + 1 == n ? "\n" : " ");
    else
      cout << (i64)1e9 << (i + 1 == n ? "\n" : " ");

  return 0;
}
