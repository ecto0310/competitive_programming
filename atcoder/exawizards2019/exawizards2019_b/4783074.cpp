// URL: https://atcoder.jp/contests/exawizards2019/submissions/4783074
// Date: Sun, 31 Mar 2019 15:00:52 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int n;
  string s;
  cin >> n >> s;
  int cntR = 0, cntB = 0;
  for (int i = 0; i < n; i++)
    if (s[i] == 'R')
      cntR++;
    else
      cntB++;
  if (cntB < cntR)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}
