// URL: https://atcoder.jp/contests/abc195/submissions/20869664
// Date: Sat, 13 Mar 2021 21:01:02 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main() {
    i64 M, H;
    cin >> M >> H;
    if (H % M == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
