// URL: https://atcoder.jp/contests/abc134/submissions/6477060
// Date: Sat, 20 Jul 2019 22:54:53 +0900
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
  vector<i64> in(n + 1), tmp(n + 1);
  vector<i64> ans, cnt(n + 1);
  for (i64 i = n; 0 < i; i--)
  {
    for (i64 j = i * 2; j <= n; j += i)
      a[i - 1] ^= a[j - 1];
    if (a[i - 1] == 1)
      ans.push_back(i);
  }
  i64 size = ans.size();
  cout << size << endl;
  for (i64 i = 0; i < size; i++)
    cout << ans[i] << (i + 1 == size ? "\n" : " ");
  return 0;
}
