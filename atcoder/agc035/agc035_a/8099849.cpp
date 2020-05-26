// URL: https://atcoder.jp/contests/agc035/submissions/8099849
// Date: Thu, 24 Oct 2019 00:03:38 +0900
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
  i64 t = 0;
  for (i64 i = 0; i < n; i++)
    t ^= a[i];
  if (t == 0)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
