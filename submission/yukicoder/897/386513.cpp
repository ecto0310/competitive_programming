// URL: https://yukicoder.me/submissions/386513
// Date: Fri, 04 Oct 2019 21:25:40 +0900
// Language: C++14
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 q;
  cin >> q;
  for (i64 _ = 0; _ < q; _++)
  {
    i64 n, k;
    cin >> n >> k;
    if (k == 1)
      cout << n - 1 << endl;
    else
    {
      i64 tmp = 1;
      for (i64 i = 0;; i++)
      {
        if (n <= tmp)
        {
          cout << i << endl;
          break;
        }
        tmp *= k;
      }
    }
  }
  return 0;
}
