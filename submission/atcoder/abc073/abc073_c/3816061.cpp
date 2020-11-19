// URL: https://atcoder.jp/contests/abc073/submissions/3816061
// Date: Mon, 17 Dec 2018 23:36:10 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int n;
  cin >> n;
  map<int, bool> m;
  while (n--)
  {
    int a;
    cin >> a;
    if (m[a] == true)
      m[a] = false;
    else
      m[a] = true;
  }
  int ans = 0;
  for (pair<int, bool> t : m)
    if (t.second == true)
      ans++;
  cout << ans << endl;

  return 0;
}
