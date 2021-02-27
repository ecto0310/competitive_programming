// URL: https://atcoder.jp/contests/abc193/submissions/20537953
// Date: Sat, 27 Feb 2021 21:36:17 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main() {
    i64 K;
    string S, T;
    cin >> K >> S >> T;
    i64 ans = 0;
    for (i64 i = 1; i < 10; i++) {
        for (i64 j = 1; j < 10; j++) {
            vector<i64> cntS(10), cntT(10), cnt(10);
            cntS[i]++;
            cnt[i]++;
            cntT[j]++;
            cnt[j]++;
            for (i64 k = 0; k < 4; k++) {
                cntS[S[k] - '0']++;
                cntT[T[k] - '0']++;
                cnt[S[k] - '0']++;
                cnt[T[k] - '0']++;
            }
            if (K < *max_element(cnt.begin(), cnt.end())) {
                continue;
            }
            i64 scoreS = 0, scoreT = 0;
            for (i64 k = 1; k < 10; k++) {
                scoreS += k * pow(10, cntS[k]);
                scoreT += k * pow(10, cntT[k]);
            }
            if (scoreT < scoreS) {
                ans += (K - cntS[i] - cntT[i] + (i == j ? 2 : 1)) * (K - cntS[j] - cntT[j] + 1);
            }
        }
    }
    cout << fixed << setprecision(7) << (double) ans / ((9 * K - 8) * (9 * K - 9)) << endl;
    return 0;
}
