// URL: https://atcoder.jp/contests/abc113/submissions/3824954
// Date: Thu, 20 Dec 2018 01:28:58 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

struct city
{
  int n, p, y, cnt;
};

bool y_s(city l, city r)
{
  return l.y < r.y;
}

bool n_s(city l, city r)
{
  return l.n < r.n;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<city> c(m);
  for (int i = 0; i < m; i++)
  {
    int p, y;
    cin >> p >> y;
    c[i] = {i, p, y, -1};
  }
  sort(c.begin(), c.end(), y_s);
  map<int, int> ma;
  for (int i = 0; i < m; i++)
  {
    c[i].cnt = ma[c[i].p] + 1;
    ma[c[i].p]++;
  }
  sort(c.begin(), c.end(), n_s);
  for (int i = 0; i < m; i++)
    cout << setfill('0') << setw(6) << right << c[i].p << setfill('0') << setw(6) << right << c[i].cnt << endl;

  return 0;
}
