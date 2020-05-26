// URL: https://codeforces.com/contest/1305/submission/72326660
// Date: Wed, 04 Mar 2020 00:10:17 +0900
// Language: GNU C++17
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  string s;
  cin >> s;
  i64 size = s.size();
  vector<vector<i64>> ans;
  while (true)
  {
    vector<i64> cntl(size + 1), cntr(size + 1);
    for (i64 i = 0; i < size; i++)
      cntl[i + 1] = cntl[i] + (s[i] == '(');
    for (i64 i = size; 0 < i; i--)
      cntr[i - 1] = cntr[i] + (s[i - 1] == ')');
    i64 m = 0, it = 0;
    for (i64 i = 0; i < size; i++)
      if (m < min(cntl[i], cntr[i]))
      {
        m = min(cntl[i], cntr[i]);
        it = i;
      }
    if (m == 0)
      break;
    vector<i64> t;
    for (i64 i = 0; i < it; i++)
      if (s[i] == '(')
      {
        t.push_back(i);
        s[i] = '-';
        if (m == t.size())
          break;
      }
    for (i64 i = size - 1; 0 < i; i--)
      if (s[i] == ')')
      {
        t.push_back(i);
        s[i] = '-';
        if (m * 2 == t.size())
          break;
      }
    sort(t.begin(), t.end());
    ans.push_back(t);
  }
  i64 asize = ans.size();
  cout << asize << "\n";
  for (i64 i = 0; i < asize; i++)
  {
    i64 isize = ans[i].size();
    cout << isize << "\n";
    for (i64 j = 0; j < isize; j++)
      cout << ans[i][j] + 1 << " \n"[j + 1 == isize];
  }
  return 0;
}
