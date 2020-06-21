// URL: https://atcoder.jp/contests/abc171/submissions/14586934
// Date: Sun, 21 Jun 2020 22:46:15 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N;
  cin >> N;
  string ans;
  N--;
  while (0 <= N)
  {
    ans += N % 26 + 'a';
    N /= 26;
    N--;
  }
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
  return 0;
}
