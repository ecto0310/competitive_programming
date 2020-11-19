// URL: https://atcoder.jp/contests/abc136/submissions/8895993
// Date: Tue, 10 Dec 2019 17:15:53 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  string s;
  cin >> s;
  vector<i64> ans(s.size());
  i64 sum = 0;
  for (i64 i = 0; i < s.size() - 1; i++)
    if (s[i] == 'R')
    {
      sum++;
      if (s[i + 1] == 'L')
      {
        ans[i + 1] += sum / 2;
        ans[i] += (sum + 1) / 2;
      }
    }
    else
      sum = 0;
  sum = 0;
  for (i64 i = s.size() - 1; 0 < i; i--)
    if (s[i] == 'L')
    {
      sum++;
      if (s[i - 1] == 'R')
      {
        ans[i - 1] += sum / 2;
        ans[i] += (sum + 1) / 2;
      }
    }
    else
      sum = 0;
  for (i64 i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  cout << endl;
  return 0;
}
