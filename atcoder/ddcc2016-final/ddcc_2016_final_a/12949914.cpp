// URL: https://atcoder.jp/contests/ddcc2016-final/submissions/12949914
// Date: Fri, 08 May 2020 17:37:58 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 R, C;
  cin >> R >> C;
  i64 ans = 0;
  for (i64 i = C; i < R; i += C)
    for (i64 j = C; j < R; j += C)
      if (i * i + j * j <= R * R)
        ans++;
  cout << ans * 4 << endl;
  return 0;
}
