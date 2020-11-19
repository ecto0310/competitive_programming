// URL: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3901622
// Date: Tue, 01 Oct 2019 13:00:23 +0900
// Language: C++14
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 l;
  cin >> l;
  vector<i64> c(l);
  for (i64 i = 0; i < l; i++)
    cin >> c[i];
  vector<i64> h;
  vector<bool> in(l);
  for (i64 i = 0; i < l; i++)
  {
    if (0 < c[i])
    {
      h.push_back(c[i]);
      if (in[c[i] - 1])
      {
        cout << i + 1 << endl;
        return 0;
      }
      in[c[i] - 1] = true;
    }
    else
    {
      if (0 < h.size() && h[h.size() - 1] == -c[i])
      {
        h.pop_back();
        in[-c[i] - 1] = false;
      }
      else
      {
        cout << i + 1 << endl;
        return 0;
      }
    }
  }
  cout << "OK" << endl;
  return 0;
}
