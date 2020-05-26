// URL: https://atcoder.jp/contests/joi2011yo/submissions/6865503
// Date: Mon, 12 Aug 2019 17:38:02 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, k;
  cin >> n >> k;
  for (i64 i = 0; i < k; i++)
  {
    i64 a, b;
    cin >> a >> b;
    cout << (min({a, b, n - a + 1, n - b + 1}) - 1) % 3 + 1 << endl;
  }
  return 0;
}
