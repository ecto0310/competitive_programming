// URL: https://atcoder.jp/contests/past202005-open/submissions/14062266
// Date: Sat, 06 Jun 2020 18:07:03 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N;
  string s[5];
  cin >> N;
  for (i64 i = 0; i < 5; i++)
    cin >> s[i];
  string ans;
  for (i64 i = 1; i < 4 * N + 1; i += 4)
  {
    if (s[0].substr(i, 3) == "###" && s[1].substr(i, 3) == "#.#" && s[2].substr(i, 3) == "#.#" && s[3].substr(i, 3) == "#.#" && s[4].substr(i, 3) == "###")
      ans += "0";
    if (s[0].substr(i, 3) == ".#." && s[1].substr(i, 3) == "##." && s[2].substr(i, 3) == ".#." && s[3].substr(i, 3) == ".#." && s[4].substr(i, 3) == "###")
      ans += "1";
    if (s[0].substr(i, 3) == "###" && s[1].substr(i, 3) == "..#" && s[2].substr(i, 3) == "###" && s[3].substr(i, 3) == "#.." && s[4].substr(i, 3) == "###")
      ans += "2";
    if (s[0].substr(i, 3) == "###" && s[1].substr(i, 3) == "..#" && s[2].substr(i, 3) == "###" && s[3].substr(i, 3) == "..#" && s[4].substr(i, 3) == "###")
      ans += "3";
    if (s[0].substr(i, 3) == "#.#" && s[1].substr(i, 3) == "#.#" && s[2].substr(i, 3) == "###" && s[3].substr(i, 3) == "..#" && s[4].substr(i, 3) == "..#")
      ans += "4";
    if (s[0].substr(i, 3) == "###" && s[1].substr(i, 3) == "#.." && s[2].substr(i, 3) == "###" && s[3].substr(i, 3) == "..#" && s[4].substr(i, 3) == "###")
      ans += "5";
    if (s[0].substr(i, 3) == "###" && s[1].substr(i, 3) == "#.." && s[2].substr(i, 3) == "###" && s[3].substr(i, 3) == "#.#" && s[4].substr(i, 3) == "###")
      ans += "6";
    if (s[0].substr(i, 3) == "###" && s[1].substr(i, 3) == "..#" && s[2].substr(i, 3) == "..#" && s[3].substr(i, 3) == "..#" && s[4].substr(i, 3) == "..#")
      ans += "7";
    if (s[0].substr(i, 3) == "###" && s[1].substr(i, 3) == "#.#" && s[2].substr(i, 3) == "###" && s[3].substr(i, 3) == "#.#" && s[4].substr(i, 3) == "###")
      ans += "8";
    if (s[0].substr(i, 3) == "###" && s[1].substr(i, 3) == "#.#" && s[2].substr(i, 3) == "###" && s[3].substr(i, 3) == "..#" && s[4].substr(i, 3) == "###")
      ans += "9";
  }
  cout << ans << endl;
  return 0;
}
