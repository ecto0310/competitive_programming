#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

class EllysWhatDidYouGet
{
public:
  int getCount(int N)
  {
    int ans = 0;
    for (int x = 1; x <= 50; x++)
      for (int y = 1; y <= 50; y++)
        for (int z = 1; z <= 50; z++)
        {
          int num = (1 * x + y) * z;
          int sum = 0;
          while (num)
          {
            sum += num % 10;
            num /= 10;
          }
          bool ok = true;
          for (int i = 1; i <= N; i++)
          {
            num = (i * x + y) * z;
            int t = 0;
            while (num)
            {
              t += num % 10;
              num /= 10;
            }
            if (sum != t)
              ok = false;
          }
          if (ok)
            ans++;
        }
    return ans;
  }
};

// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
