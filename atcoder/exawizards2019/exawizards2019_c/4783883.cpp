// URL: https://atcoder.jp/contests/exawizards2019/submissions/4783883
// Date: Sun, 31 Mar 2019 16:06:35 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int n, q;
string s;
vector<char> d, t;

int pos(int now)
{
  for (int i = 0; i < q; i++)
    if (s[now] == d[i])
    {
      if (t[i] == 'L')
        now--;
      else
        now++;
      if (now < 0)
        return -1;
      if (n <= now)
        return 1;
    }
  return 0;
}

int main()
{
  cin >> n >> q >> s;
  d.resize(q);
  t.resize(q);
  for (int i = 0; i < q; i++)
    cin >> d[i] >> t[i];
  int l, r;
  int ok = n, ng = -1;
  while (ok - ng > 1)
  {
    int mid = (ok + ng) / 2;
    if (pos(mid) == -1)
      ng = mid;
    else
      ok = mid;
  }
  l = ok;
  ok = -1, ng = n;
  while (ng - ok > 1)
  {
    int mid = (ok + ng) / 2;
    if (pos(mid) == 1)
      ng = mid;
    else
      ok = mid;
  }
  r = ok;
  cout << r - l + 1 << endl;

  return 0;
}
