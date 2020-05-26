// URL: https://atcoder.jp/contests/abc141/submissions/7514372
// Date: Sun, 15 Sep 2019 21:01:17 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  string s;
  cin >> s;
  if (s == "Sunny")
    cout << "Cloudy" << endl;
  else if (s == "Cloudy")
    cout << "Rainy" << endl;
  else
    cout << "Sunny" << endl;
  return 0;
}
