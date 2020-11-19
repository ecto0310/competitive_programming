#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

class EllysDifferentPrimes
{
  bool prime(int n)
  {
    if (n <= 1)
      return false;
    int s = sqrt(n);
    for (int i = 2; i <= s; i++)
      if (n % i == 0)
        return false;
    int bit = 0;
    while (n)
    {
      if (bit & (1 << (n % 10)))
        return false;
      bit |= (1 << (n % 10));
      n /= 10;
    }
    return true;
  }

public:
  int getClosest(int N)
  {
    for (int i = 0;; i++)
    {
      if (prime(N - i))
        return N - i;
      if (prime(N + i))
        return N + i;
    }
    return 2;
  }
};

// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
