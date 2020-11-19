// URL: https://atcoder.jp/contests/abc114/submissions/3704927
// Date: Sun, 02 Dec 2018 21:35:43 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int n;

char add[] = {'7', '5', '3'};

int dfs(string now, bool t7, bool t5, bool t3)
{
	if (0 < now.size() && n < stoll(now))
		return 0;
	int ret = (t7 == true && t5 == true && t3 == true);
	ret += dfs('7' + now, true, t5, t3);
	ret += dfs('5' + now, t7, true, t3);
	ret += dfs('3' + now, t7, t5, true);

	return ret;
}

int main()
{
	cin >> n;
	cout << dfs("", false, false, false) << endl;

	return 0;
}
