// URL: https://atcoder.jp/contests/abc126/submissions/5449299
// Date: Sun, 19 May 2019 21:03:20 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, k;
  string s;
  cin >> n >> k >> s;
  s[k - 1] = s[k - 1] - 'A' + 'a';
  cout << s << endl;
  return 0;
}
