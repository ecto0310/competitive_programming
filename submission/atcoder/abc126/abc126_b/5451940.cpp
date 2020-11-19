// URL: https://atcoder.jp/contests/abc126/submissions/5451940
// Date: Sun, 19 May 2019 21:07:13 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  string s;
  cin >> s;
  if (0 < stoi(s.substr(0, 2)) && stoi(s.substr(0, 2)) <= 12 && 0 < stoi(s.substr(2, 2)) && stoi(s.substr(2, 2)) <= 12)
    cout << "AMBIGUOUS" << endl;
  else if (0 < stoi(s.substr(0, 2)) && stoi(s.substr(0, 2)) <= 12)
    cout << "MMYY" << endl;
  else if (0 < stoi(s.substr(2, 2)) && stoi(s.substr(2, 2)) <= 12)
    cout << "YYMM" << endl;
  else
    cout << "NA" << endl;
  return 0;
}
