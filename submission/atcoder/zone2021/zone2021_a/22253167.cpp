// URL: https://atcoder.jp/contests/zone2021/submissions/22253167
// Date: Sun, 02 May 2021 14:47:21 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main() {
    string S;
    cin >> S;
    i64 ans = 0;
    for (i64 i = 0; i < S.size() - 3; i++) {
        if (S.substr(i, 4) == "ZONe") {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
