// URL: https://atcoder.jp/contests/chokudai_S001/submissions/9539177
// Date: Fri, 17 Jan 2020 01:19:23 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<i64> a(n);
  for (i64 i = 0; i < n; i++)
    cin >> a[i];
  sort(a.begin(), a.end());
  for (i64 i = 0; i < n; i++)
    cout << a[i] << (i + 1 == n ? "\n" : " ");
  return 0;
}
