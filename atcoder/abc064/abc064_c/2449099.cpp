// URL: https://atcoder.jp/contests/abc064/submissions/2449099
// Date: Thu, 03 May 2018 13:52:55 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	set<string> s;
	int free = 0;
	for(int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		if(1 <= a && a < 400)s.insert("gray");
		else if(400 <= a && a < 800)s.insert("brown");
		else if(800 <= a && a < 1200)s.insert("green");
		else if(1200 <= a && a < 1600)s.insert("water");
		else if(1600 <= a && a < 2000)s.insert("blue");
		else if(2000 <= a && a < 2400)s.insert("yellow");
		else if(2400 <= a && a < 2800)s.insert("orange");
		else if(2800 <= a && a < 3200)s.insert("red");
		else free++;
	}
	if(s.size() == 0)cout << 1 << " " << free << endl;
	else cout << s.size() << " " << s.size() + free << endl;

	return 0;
}
