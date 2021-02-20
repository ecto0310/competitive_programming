// URL: https://atcoder.jp/contests/abc192/submissions/20292039
// Date: Sat, 20 Feb 2021 21:06:30 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main() {
    string N;
    i64 K;
    cin >> N >> K;
    for (i64 i = 0; i < K; i++) {
        sort(N.begin(), N.end());
        i64 g2 = stoll(N);
        reverse(N.begin(), N.end());
        i64 g1 = stoll(N);
        N = to_string(g1 - g2);
    }
    cout << N << endl;
    return 0;
}
