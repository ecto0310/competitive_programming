// URL: https://atcoder.jp/contests/panasonic2020/submissions/10856353
// Date: Sat, 14 Mar 2020 21:29:34 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

i64 dfs(i64 now, char t, string s)
{
  if (now == 0)
  {
    cout << s << endl;
    return 0;
  }
  for (char i = 'a'; i <= t; i++)
    dfs(now - 1, max(t, (char)(i + 1)), s + i);
  return 0;
}

int main()
{
  i64 N;
  cin >> N;
  dfs(N, 'a', "");
  return 0;
}
