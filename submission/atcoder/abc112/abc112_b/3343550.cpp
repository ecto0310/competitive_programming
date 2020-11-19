// URL: https://atcoder.jp/contests/abc112/submissions/3343550
// Date: Sat, 06 Oct 2018 21:05:51 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int n, tl;
  cin >> n >> tl;
  int ans = -1, now = 10000;
  for (int i = 0; i < n; i++)
  {
    int c, t;
    cin >> c >> t;
    if (t <= tl && c <= now)
    {
      ans = i + 1;
      now = c;
    }
  }
  if (ans != -1)
    cout << now << endl;
  else
    cout << "TLE" << endl;

  return 0;
}
