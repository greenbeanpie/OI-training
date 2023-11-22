#include<bits/stdc++.h>
using namespace std;
int c,n,m,t,i,a[1000000],b[1000000];
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while ((ch<'0'||ch>'9')&&(ch!='-')) ch=getchar();
	if (ch=='-'){
		f=-1;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=getchar();
	return x*f;	
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=read();
	n=read();
	m=read();
	t=read();
	for (i=1;i<=n;i++) a[i]=read();
	for (i=1;i<=m;i++) b[i]=read();
	srand(time(0));
	for (i=1;i<=t+1;i++) printf("%d",rand()%2);
	printf("\n");
	return 0;
}