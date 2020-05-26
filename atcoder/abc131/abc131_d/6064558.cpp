// URL: https://atcoder.jp/contests/abc131/submissions/6064558
// Date: Sat, 22 Jun 2019 21:27:42 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<pair<i64, i64>> t(n);
  for (i64 i = 0; i < n; i++)
    cin >> t[i].second >> t[i].first;
  sort(t.begin(), t.end());
  bool ans = true;
  i64 now = 0;
  for (i64 i = 0; i < n; i++)
  {
    now += t[i].second;
    if (t[i].first < now)
      ans = false;
  }
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}
