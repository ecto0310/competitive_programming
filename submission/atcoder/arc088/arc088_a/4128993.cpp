// URL: https://atcoder.jp/contests/arc088/submissions/4128993
// Date: Wed, 30 Jan 2019 23:08:53 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  long long X, Y;
  cin >> X >> Y;
  long long ans = 0;
  while (X <= Y)
  {
    X *= 2;
    ans++;
  }
  cout << ans << endl;

  return 0;
}
