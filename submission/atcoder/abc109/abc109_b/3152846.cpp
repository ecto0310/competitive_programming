// URL: https://atcoder.jp/contests/abc109/submissions/3152846
// Date: Sat, 08 Sep 2018 21:05:25 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int n;
  cin >> n;
  string w[100];
  for (int i = 0; i < n; i++)
    cin >> w[i];
  map<string, bool> m;
  m[w[0]] = true;
  bool ok = true;
  for (int i = 1; i < n; i++)
  {
    if (m[w[i]] || w[i][0] != w[i - 1][w[i - 1].length() - 1])
      ok = false;
    m[w[i]] = true;
  }
  if (ok)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}
