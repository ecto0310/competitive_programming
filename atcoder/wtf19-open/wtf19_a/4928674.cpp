// URL: https://atcoder.jp/contests/wtf19-open/submissions/4928674
// Date: Fri, 12 Apr 2019 22:21:49 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, k;
  cin >> n >> k;
  vector<i64> a(n);
  for (i64 i = 0; i < n; i++)
    cin >> a[i];
  bool ok = true;
  vector<i64> ans;
  i64 now = -1;
  for (i64 i = 0; i < k + 1; i++)
  {
    i64 pos = -1, mi = 1e9;
    for (i64 j = 0; j < n; j++)
      if (j != now && a[j] <= mi)
      {
        pos = j;
        mi = a[j];
      }
    for (i64 j = 0; j < n; j++)
      if (j != now && j != pos)
      {
        ans.push_back(j + 1);
        a[j]--;
        if (a[j] < 0)
          ok = false;
      }
    ans.push_back(pos + 1);
    a[pos]--;
    if (a[pos] < 0)
      ok = false;
    now = pos;
  }
  if (ok)
  {
    i64 size = ans.size();
    cout << size << endl;
    for (i64 i = 0; i < size; i++)
      cout << ans[i] << (i + 1 == size ? "\n" : " ");
  }
  else
    cout << "-1" << endl;
  return 0;
}
