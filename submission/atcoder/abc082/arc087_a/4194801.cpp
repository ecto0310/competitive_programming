// URL: https://atcoder.jp/contests/abc082/submissions/4194801
// Date: Fri, 08 Feb 2019 15:33:05 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int N;
  cin >> N;
  map<int, int> m;
  for (int i = 0; i < N; i++)
  {
    int a;
    cin >> a;
    m[a]++;
  }
  int ans = 0;
  for (pair<int, int> t : m)
  {
    if (t.first < t.second)
      ans += t.second - t.first;
    else if (t.second < t.first)
      ans += t.second;
  }
  cout << ans << endl;

  return 0;
}
