// URL: https://atcoder.jp/contests/chokudai_S001/submissions/9539145
// Date: Fri, 17 Jan 2020 01:16:12 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<i64> a(n);
  for (i64 i = 0; i < n; i++)
    cin >> a[i];
  cout << *max_element(a.begin(), a.end()) << endl;
  return 0;
}
