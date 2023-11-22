#include <bits/stdc++.h>
using namespace std;
int R(int mod)
{
	return (1ll*rand()*rand()+rand())%mod;
}
int main ()
{
	srand(time(0)*922+1120+421);
	puts ("10 1");
	puts ("100000 1000 10000 1");
	for (int i=1;i<=1000;i++)
	{
		int l=R(100000)+1,r=R(100000)+1,v=R(1000000000)+1;
		if (l>r) swap(l,r);
		printf ("%d %d %d\n",r,r-l+1,v);
	}
}
