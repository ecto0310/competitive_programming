// URL: https://atcoder.jp/contests/abc180/submissions/18063803
// Date: Thu, 12 Nov 2020 20:28:46 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N;
  cin >> N;
  vector<i64> ans;
  for (i64 i = 1; i <= sqrt(N); i++)
    if (N % i == 0)
    {
      ans.push_back(i);
      if (N / i != i)
        ans.push_back(N / i);
    }
  sort(ans.begin(), ans.end());
  for (i64 i = 0; i < ans.size(); i++)
    cout << ans[i] << endl;
  return 0;
}
