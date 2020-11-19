// URL: https://atcoder.jp/contests/past202005-open/submissions/14062273
// Date: Sat, 06 Jun 2020 18:07:16 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

const i64 MAX = 1e9;

i64 pow(i64 def, i64 x, i64 n)
{
  i64 ret = def;
  while (n > 0)
  {
    if (n & 1)
      ret = ret * x;
    x = x * x;
    n >>= 1;
    if (ret < 0 || MAX < ret)
      break;
  }
  if (ret < 0 || MAX < ret)
    return -1;
  return ret;
}

int main()
{
  i64 A, R, N;
  cin >> A >> R >> N;
  i64 ans = pow(A, R, N - 1);
  if (ans == -1)
    cout << "large" << endl;
  else
    cout << ans << endl;
  return 0;
}
