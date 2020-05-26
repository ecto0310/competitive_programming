// URL: https://atcoder.jp/contests/abc061/submissions/3816355
// Date: Tue, 18 Dec 2018 00:26:12 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  long long n, k;
  cin >> n >> k;
  map<int, long long> m;
  for (int i = 0; i < n; i++)
  {
    int a, b;
    cin >> a >> b;
    m[a] += b;
  }
  for (pair<int, long long> t : m)
  {
    cerr << t.first << " " << t.second << endl;
    if (k <= t.second)
    {
      cout << t.first << endl;
      return 0;
    }
    k -= t.second;
  }

  return 0;
}
