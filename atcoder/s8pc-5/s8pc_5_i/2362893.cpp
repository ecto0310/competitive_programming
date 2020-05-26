// URL: https://atcoder.jp/contests/s8pc-5/submissions/2362893
// Date: Sun, 15 Apr 2018 20:39:22 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
	int H, W, N;
	cin >> H >> W >> N;
	cout << 0 << endl;
	bool rm = true;
	string re;
	for( int i = 0; i < H; i++ )
	{
		for( int j = 0; j < W - 1; j++ )
		{
			if( rm )cout << "R" << endl;
			else cout << "L" << endl;
			cin >> re;
			if( re == "get-clear" )return 0;
		}
		cout << "D" << endl;
		cin >> re;
		if( re == "get-clear" )return 0;
		rm = ( rm ? false : true );
	}

	return 0;
}
