#include<bits/stdc++.h>
using namespace std;
long long read()
{
	long long x=0;int w=1;
	char ch='0';
	
		ch=getchar();

	while(ch>='0'&&ch<='9')
	{
	x=x*10+(ch-'0');
		ch=getchar();
	}
	return (long long)x*w;
}
int main(){
	/*freopen(".in","r",stdin);
	freopen(".out","w",stdout);*/
	long long aa;
	aa=read();
	cout<<aa<<endl;
	return 0;
}
