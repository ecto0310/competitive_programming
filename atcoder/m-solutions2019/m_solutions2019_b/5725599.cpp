// URL: https://atcoder.jp/contests/m-solutions2019/submissions/5725599
// Date: Sat, 01 Jun 2019 21:02:48 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  string s;
  cin >> s;
  i64 cnt = 0;
  for (i64 i = 0; i < s.size(); i++)
    if (s[i] == 'o')
      cnt++;
  if (8 <= cnt + 15 - s.size())
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
