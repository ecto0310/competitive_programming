// URL: https://atcoder.jp/contests/ddcc2016-qual/submissions/4797403
// Date: Mon, 01 Apr 2019 22:02:41 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

int r;
double n,m;

double calc(int i)
{
	if(i<=0||n<=i)
		return 0;
	return sqrt(pow(r,2)-pow(fabs(r-2*r/n*i),2))*2;
}

int main()
{
	cin>>r>>n>>m;
	double ans=0;
	for(int i=0;i<n+m;i++)
		ans+=max(calc(i),calc(i-m));
	cout<< fixed<< setprecision(7)<< ans<< endl;

	return 0;
}
