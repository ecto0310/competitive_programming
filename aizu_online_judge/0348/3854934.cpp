// URL: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3854934
// Date: Mon, 09 Sep 2019 15:16:10 +0900
// Language: C++14
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

bool dfs(bool t, set<i64> a, set<i64> b, i64 l, i64 r)
{
  if (a.size() == 0)
    return true;
  if (b.size() == 0)
    return false;
  bool ret;
  set<i64> tmp;
  if (t)
  {
    ret = false;
    if (a.find(l - 1) != a.end())
    {
      tmp = a;
      tmp.erase(l - 1);
      ret |= dfs(!t, tmp, b, l - 1, r);
    }
    if (a.find(r + 1) != a.end())
    {
      tmp = a;
      tmp.erase(r + 1);
      ret |= dfs(!t, tmp, b, l, r + 1);
    }
    if (a.find(l - 1) == a.end() && a.find(r + 1) == a.end())
      ret = dfs(!t, a, b, l, r);
  }
  else
  {
    ret = true;
    if (b.find(l - 1) != b.end())
    {
      tmp = b;
      tmp.erase(l - 1);
      ret &= dfs(!t, a, tmp, l - 1, r);
    }
    if (b.find(r + 1) != b.end())
    {
      tmp = b;
      tmp.erase(r + 1);
      ret &= dfs(!t, a, tmp, l, r + 1);
    }
    if (b.find(l - 1) == b.end() && b.find(r + 1) == b.end())
      ret = dfs(!t, a, b, l, r);
  }
  return ret;
}

int main()
{
  i64 n;
  cin >> n;
  for (i64 _ = 0; _ < n; _++)
  {
    set<i64> a, b;
    for (i64 i = 0; i < 6; i++)
    {
      i64 k;
      cin >> k;
      a.insert(k);
    }
    for (i64 i = 1; i <= 13; i++)
      if (i != 7 && a.find(i) == a.end())
        b.insert(i);
    if (dfs(true, a, b, 7, 7))
      cout << "yes" << endl;
    else
      cout << "no" << endl;
  }
  return 0;
}
