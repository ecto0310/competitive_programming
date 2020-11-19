// URL: https://atcoder.jp/contests/ttpc2019/submissions/7659981
// Date: Mon, 23 Sep 2019 00:59:18 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  for (i64 i = 0; i < n; i++)
  {
    string s;
    cin >> s;
    smatch t;
    if (regex_match(s, t, regex("[a-z]*okyo[a-z]*ech[a-z]*")))
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}
