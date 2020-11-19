// URL: https://atcoder.jp/contests/abc005/submissions/4642601
// Date: Wed, 20 Mar 2019 23:07:23 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int t, n;
  cin >> t >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int m;
  cin >> m;

  vector<int> b(m);
  for (int i = 0; i < m; i++)
    cin >> b[i];
  int now = 0;
  for (int i = 0; i < n; i++)
  {
    if (a[i] + t >= b[now] && a[i] <= b[now])
      now++;
    if (now == m)
      break;
  }
  if (now == m)
    cout << "yes" << endl;
  else
    cout << "no" << endl;

  return 0;
}
