// URL: https://atcoder.jp/contests/abc150/submissions/9492016
// Date: Mon, 13 Jan 2020 15:13:03 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<i64> p(n), q(n);
  for (i64 i = 0; i < n; i++)
    cin >> p[i];
  for (i64 i = 0; i < n; i++)
    cin >> q[i];
  vector<i64> t = p;
  sort(t.begin(), t.end());
  i64 pn, qn, cnt = 0;
  do
  {
    if (t == p)
      pn = cnt;
    if (t == q)
      qn = cnt;
    cnt++;
  } while (next_permutation(t.begin(), t.end()));
  cout << abs(pn - qn) << endl;
  return 0;
}
