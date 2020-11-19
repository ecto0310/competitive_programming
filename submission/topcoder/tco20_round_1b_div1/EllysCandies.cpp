#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

class EllysCandies
{
public:
  string getWinner(vector<int> boxes)
  {
    if (boxes.size() % 2 == 0)
      return "Kris";
    else
      return "Elly";
  }
};

// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
