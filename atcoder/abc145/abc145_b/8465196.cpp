// URL: https://atcoder.jp/contests/abc145/submissions/8465196
// Date: Sat, 16 Nov 2019 21:02:18 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  string s;
  cin >> n >> s;
  if (n % 2 == 0 && s.substr(0, n / 2) == s.substr(n / 2 , n / 2))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
