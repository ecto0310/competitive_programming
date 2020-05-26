// URL: https://codingcompetitions.withgoogle.com/codejam/submissions/000000000019fd27/ZWN0bzAzMTA
// Date: Sat, 04 Apr 2020 12:17:03 +0900
// Language: C++14 (G++)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 T;
  cin >> T;
  for (i64 _ = 1; _ <= T; _++)
  {
    string S;
    cin >> S;
    string ans;
    i64 c = 0;
    for (char i : S)
    {
      i64 t = c - (i - '0');
      if (0 < t)
      {
        ans += string(t, ')');
      }
      else if (t < 0)
      {
        ans += string(abs(t), '(');
      }
      ans += i;
      c = i - '0';
    }
    ans += string(c, ')');
    cout << "Case #" << _ << ": " << ans << endl;
  }
  return 0;
}
