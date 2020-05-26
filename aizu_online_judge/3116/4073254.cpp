// URL: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=4073254
// Date: Wed, 25 Dec 2019 09:34:44 +0900
// Language: C++14
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, q;
  cin >> n >> q;
  vector<i64> a(n);
  for (i64 i = 0; i < n; i++)
    cin >> a[i];
  sort(a.begin(), a.end());
  for (i64 _ = 0; _ < q; _++)
  {
    i64 l, r;
    cin >> l >> r;
    i64 ri = upper_bound(a.begin(), a.end(), r) - a.begin();
    i64 li = lower_bound(a.begin(), a.end(), l) - a.begin();
    cout << ri - li << endl;
  }
  return 0;
}
