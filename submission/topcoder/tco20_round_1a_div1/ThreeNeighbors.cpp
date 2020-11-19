#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

class ThreeNeighbors
{
public:
  vector<string> construct(int N)
  {
    vector<string> ans(50, string(50, '.'));
    for (int i = 0; i < 12; i++)
      for (int j = 0; j < 12; j++)
      {
        if (1 <= N && N != 2)
          ans[i * 4][j * 4 + 1] = 'X';
        if (1 <= N)
          ans[i * 4 + 1][j * 4] = 'X';
        if (1 <= N)
          ans[i * 4 + 1][j * 4 + 1] = 'X';
        if (2 <= N)
          ans[i * 4 + 1][j * 4 + 2] = 'X';
        if (4 <= N)
          ans[i * 4 + 2][j * 4 + 1] = 'X';
        N -= 4;
      }
    return ans;
  }
};

// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
