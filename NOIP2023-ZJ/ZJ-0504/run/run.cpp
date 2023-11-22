#include<bits/stdc++.h>
using namespace std;
#define int long long
int x[1000010],y[1000010],z[1000010],n,m,k,d,ans,q,ma;
int read() {
	int x=0,f=1;
	char ch=getchar();
	for(; ch<'0'||ch>'9'; ch=getchar()) if (ch=='-') f=-1;
	for(; ch>='0'&&ch<='9'; ch=getchar()) x=x*10+ch-48;
	return x*f;
}
void write(int x) {
	if (x<0) x=-x,putchar('-');
	if (x<10) putchar(x+48);
	if (x==0) return;
	write(x/10);
}
int maxn(int x,int y){
	return x>y?x:y;
}
signed main() {
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	q=read();
	for(int T=read(); T; T--) {
		ma=-2147483647;
		n=read(),m=read(),k=read(),d=read();
		for(int i=1; i<=m; i++)
			x[i]=read(),y[i]=read(),z[i]=read(),ma=max(ma,y[i]);
		ans=0;
		q=0;
		int s=0;
		for(int k=1; k<=n; k++)  
		{
			if (k==q) {
				q=0;
				continue;
			}
			q++;s++;
		}
		for(int i=1;i<=m;i++) if (s>y[i]) ans+=z[i];
		printf("%lld\n",ans-ma);
	}

	return 0;
}

