// URL: https://atcoder.jp/contests/abc153/submissions/9733175
// Date: Sun, 26 Jan 2020 21:02:50 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 h, n;
  cin >> h >> n;
  vector<i64> a(n);
  for (i64 i = 0; i < n; i++)
    cin >> a[i];
  i64 sum = 0;
  for (i64 i = 0; i < n; i++)
    sum += a[i];
  if (sum < h)
    cout << "No" << endl;
  else
    cout << "Yes" << endl;
  return 0;
}
