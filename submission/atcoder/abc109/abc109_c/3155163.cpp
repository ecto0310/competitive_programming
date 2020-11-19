// URL: https://atcoder.jp/contests/abc109/submissions/3155163
// Date: Sat, 08 Sep 2018 21:17:22 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int gcd(int x,int y)
{
  return (x%y==0?y:gcd(y,x%y));
}

int main()
{
  int n, x;
  cin >> n >> x;
  vector<int> p(n);
  for (int i = 0; i < n; i++)
  {
    cin >> p[i];
    p[i] = abs(p[i] - x);
  }
  int ans = p[0];
  for (int i = 1; i < n; i++)
    ans = gcd(ans, p[i]);
  cout << ans << endl;

  return 0;
}
