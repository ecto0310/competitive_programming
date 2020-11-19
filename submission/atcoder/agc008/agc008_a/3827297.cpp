// URL: https://atcoder.jp/contests/agc008/submissions/3827297
// Date: Thu, 20 Dec 2018 17:59:30 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int x, y;
  cin >> x >> y;
  int ans = INT_MAX;
  for (int i = -1; i < 2; i += 2)
    for (int j = -1; j < 2; j += 2)
      if (i * x <= j * y)
        ans = min(ans, j * y - i * x + (i == -1 ? 1 : 0) + (j == -1 ? 1 : 0));
  cout << ans << endl;

  return 0;
}
