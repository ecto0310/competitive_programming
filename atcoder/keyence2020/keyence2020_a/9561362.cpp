// URL: https://atcoder.jp/contests/keyence2020/submissions/9561362
// Date: Sat, 18 Jan 2020 21:01:08 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 h, w, n;
  cin >> h >> w >> n;
  if (h < w)
    cout << (n + w - 1) / w << endl;
  else
    cout << (n + h - 1) / h << endl;
  return 0;
}
