// URL: https://atcoder.jp/contests/agc038/submissions/7659215
// Date: Sun, 22 Sep 2019 23:52:54 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 h, w, a, b;
  cin >> h >> w >> a >> b;
  for (i64 i = 0; i < h; i++)
  {
    for (i64 j = 0; j < w; j++)
      cout << (((i < b) ^ (j < a)) ? 0 : 1);
    cout << endl;
  }
  return 0;
}
