// URL: https://yukicoder.me/submissions/392877
// Date: Fri, 25 Oct 2019 20:28:13 +0900
// Language: C++14
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 a, b, c, d;
  cin >> a >> b >> c >> d;
  if (10 <= d)
    cout << "Impossible" << endl;
  else
  {
    i64 ans = 0;
    i64 bon = 1;
    i64 sum = a + b;
    for (i64 i = 0; i < sum; i++)
    {
      if (0 < b)
      {
        ans += 50 * bon;
        b--;
      }
      else
        ans += 100 * bon;
      if ((i + 1) % 100 == 0)
        bon *= 2;
    }
    cout << "Possible" << endl
         << ans << endl;
  }
  return 0;
}
