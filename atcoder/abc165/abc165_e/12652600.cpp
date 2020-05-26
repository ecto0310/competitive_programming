// URL: https://atcoder.jp/contests/abc165/submissions/12652600
// Date: Sat, 02 May 2020 23:06:44 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N, M;
  cin >> N >> M;
  if (N % 2 == 0)
  {
    for (i64 i = 1; i <= M; i++)
    {
      if (N / 2 < N + 1 - 2 * i)
        cout << i << " " << N - i + 1 << endl;
      else
        cout << i << " " << N - i << endl;
    }
  }
  else
    for (i64 i = 1; i <= M; i++)
      cout << i << " " << N - i + 1 << endl;

  return 0;
}
