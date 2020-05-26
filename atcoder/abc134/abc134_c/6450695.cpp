// URL: https://atcoder.jp/contests/abc134/submissions/6450695
// Date: Sat, 20 Jul 2019 21:04:42 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<i64> a(n);
  for (i64 i = 0; i < n; i++)
    cin >> a[i];
  vector<i64> tmp = a;
  sort(tmp.begin(), tmp.end(), greater<i64>());
  for (i64 i = 0; i < n; i++)
    if (a[i] == tmp[0])
      cout << tmp[1] << endl;
    else
      cout << tmp[0] << endl;
  return 0;
}
