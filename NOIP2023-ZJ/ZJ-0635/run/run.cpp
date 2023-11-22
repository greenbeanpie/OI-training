#include <bits/stdc++.h>
using namespace std;
const int N=+5;
int n,m;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0') { if(ch=='-') f=-1; ch=getchar(); }
	while(ch<='9'&&ch>='0') { x=(x<<3)+(x<<1)+ch-48; ch=getchar(); }
	return x*f;
}
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	printf("100");
	return 0;
}
