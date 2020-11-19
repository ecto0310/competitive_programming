// URL: https://atcoder.jp/contests/s8pc-5/submissions/2365245
// Date: Sun, 15 Apr 2018 23:41:11 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

float min(float x, float y)
{
	return ( x > y ? y : x );
}

int main()
{
	int N, M;
	cin >> N >> M;
	int xN[100], yN[100], rN[100];
	int xM[100], yM[100];
	for( int i = 0; i < N; i++ )cin >> xN[i] >> yN[i] >> rN[i];
	for( int i = 0; i < M; i++ )cin >> xM[i] >> yM[i];
	float ret=200.0;
	for(int i=0;i<N;i++)ret=min(ret,rN[i]);
	for( int i = 0; i < M; i++ )
	{
		for( int j = i + 1; j < M; j++ )
		{
			ret = min(ret, sqrt(pow(xM[i] - xM[j], 2) + pow(yM[i] - yM[j], 2))/2);
		}
		for(int j=0;j<N;j++)
		{
			ret = min(ret,sqrt(pow(xM[i] - xN[j], 2) + pow(yM[i] - yN[j], 2))-rN[j]);
		}
	}
	cout << fixed << setprecision(7) << ret << endl;
	return 0;
}
