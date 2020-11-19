#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

class AveragePrice
{
public:
  double nonDuplicatedAverage(vector<int> prices)
  {
    i64 sum = 0;
    set<i64> s;
    for (int i : prices)
      s.insert(i);
    for (i64 i : s)
      sum += i;
    return (double)sum / s.size();
  }
};

// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
