// URL: https://atcoder.jp/contests/abc019/submissions/5399346
// Date: Tue, 14 May 2019 20:51:31 +0900
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
  sort(a.begin(), a.end());
  set<i64> s;
  for (i64 i = 0; i < n; i++)
  {
    while (a[i] % 2 == 0)
      a[i] /= 2;
    s.insert(a[i]);
  }
  cout << s.size() << endl;
  return 0;
}
