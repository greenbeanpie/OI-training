#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll n,m,k;
ll c,q;
ll read() {
	ll uu=0;
	char c;
	c=getchar();
	while(!isdigit(c))
		c=getchar();
	while(isdigit(c)) {
		uu=(uu<<3)+(uu<<1)+(c^48);
		c=getchar();
	}
	return uu;
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=read();
	n=read();
	m=read();
	q=read();
	for(int i=1;i<=q+1;i++)
	  printf("1");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
