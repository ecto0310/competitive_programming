// URL: https://atcoder.jp/contests/abc073/submissions/4632820
// Date: Tue, 19 Mar 2019 20:46:23 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

const int MOD = 1e9 + 7;

int main()
{
  int n;
  cin >> n;
  map<int, bool> flag;
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    if (flag[a])
      flag[a] = false;
    else
      flag[a] = true;
  }
  int ans = 0;
  for (pair<int, bool> t : flag)
    if (t.second)
      ans++;
  cout << ans << endl;

  return 0;
}
