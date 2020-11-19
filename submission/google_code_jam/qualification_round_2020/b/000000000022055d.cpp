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
