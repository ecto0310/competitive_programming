// URL: https://yukicoder.me/submissions/392855
// Date: Fri, 25 Oct 2019 19:56:35 +0900
// Language: C++14
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  cout << 3 << " " << 1 << " ";
  for (i64 i = 2; i < n; i++)
    cout << 3 << (i + 1 == n ? "\n" : " ");
  return 0;
}
