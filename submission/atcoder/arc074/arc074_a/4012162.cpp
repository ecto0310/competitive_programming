// URL: https://atcoder.jp/contests/arc074/submissions/4012162
// Date: Mon, 14 Jan 2019 11:18:23 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int H, W;
  cin >> H >> W;
  long long ans = 1e10;
  if (H % 3 == 0)
    ans = 0;
  else
    ans = min(ans, (long long)W);
  if (W % 3 == 0)
    ans = 0;
  else
    ans = min(ans, (long long)H);
  for (int i = 0; i < H; i++)
  {
    long long a = (long long)i * W, b = (long long)(H - i) * (W / 2), c = (long long)(H - i) * ((W + 1) / 2);
    ans = min(ans, max({a, b, c}) - min({a, b, c}));
  }
  for (int i = 0; i < W; i++)
  {
    long long a = (long long)i * H, b = (long long)(W - i) * (H / 2), c = (long long)(W - i) * ((H + 1) / 2);
    ans = min(ans, max({a, b, c}) - min({a, b, c}));
  }
  cout << ans << endl;

  return 0;
}
