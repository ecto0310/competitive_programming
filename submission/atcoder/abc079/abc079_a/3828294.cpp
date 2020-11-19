// URL: https://atcoder.jp/contests/abc079/submissions/3828294
// Date: Thu, 20 Dec 2018 21:16:12 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  string n;
  cin >> n;
  cout << ((n[0] == n[1] && n[1] == n[2] || n[1] == n[2] && n[2] == n[3]) ? "Yes" : "No") << endl;

  return 0;
}
