// URL: https://atcoder.jp/contests/abc051/submissions/3677907
// Date: Tue, 27 Nov 2018 23:43:20 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int sx, sy, tx, ty;
	cin >> sx >> sy >> tx >> ty;
	int dx = tx - sx, dy = ty - sy;
	for (int i = 0; i < dy; i++)
		cout << "U";
	for (int i = 0; i < dx; i++)
		cout << "R";
	for (int i = 0; i < dy; i++)
		cout << "D";
	for (int i = 0; i < dx; i++)
		cout << "L";
	cout << "L";
	for (int i = 0; i < dy + 1; i++)
		cout << "U";
	for (int i = 0; i < dx + 1; i++)
		cout << "R";
	cout << "D";
	cout << "R";
	for (int i = 0; i < dy + 1; i++)
		cout << "D";
	for (int i = 0; i < dx + 1; i++)
		cout << "L";
	cout << "U"<< endl;

	return 0;
}
