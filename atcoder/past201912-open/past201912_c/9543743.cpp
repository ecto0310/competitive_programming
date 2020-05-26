// URL: https://atcoder.jp/contests/past201912-open/submissions/9543743
// Date: Fri, 17 Jan 2020 15:39:39 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  vector<i64> a(6);
  for (i64 i = 0; i < 6; i++)
    cin >> a[i];
  sort(a.begin(), a.end());
  cout << a[3] << endl;
  return 0;
}
