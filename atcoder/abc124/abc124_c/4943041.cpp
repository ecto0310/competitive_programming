// URL: https://atcoder.jp/contests/abc124/submissions/4943041
// Date: Sat, 13 Apr 2019 21:07:20 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  string s;
  cin >> s;
  i64 ans[2] = {};
  i64 size = s.size();
  for (i64 i = 0; i < size; i++)
    if (i % 2 == 0)
    {
      if (s[i] == '0')
        ans[0]++;
      else
        ans[1]++;
    }
    else
    {
      if (s[i] == '0')
        ans[1]++;
      else
        ans[0]++;
    }
  cout << min(ans[0], ans[1]) << endl;

  return 0;
}
