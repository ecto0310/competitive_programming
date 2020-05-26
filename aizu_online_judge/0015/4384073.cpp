// URL: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=4384073
// Date: Tue, 21 Apr 2020 23:01:39 +0900
// Language: C++14
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N;
  cin >> N;
  for (i64 _ = 0; _ < N; _++)
  {
    string a, b;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    string ans;
    bool up = false;
    for (i64 i = 0; i < max(a.size(), b.size()); i++)
    {
      i64 n = (i < a.size() ? a[i] - '0' : 0) + (i < b.size() ? b[i] - '0' : 0) + (up);
      up = 10 <= n;
      ans += (char)((n % 10) + '0');
    }
    if (up)
      ans += "1";
    reverse(ans.begin(), ans.end());
    if (80 < ans.size())
      cout << "overflow" << endl;
    else
      cout << ans << endl;
  }
  return 0;
}
