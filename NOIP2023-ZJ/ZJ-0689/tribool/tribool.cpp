#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
inline ll read() {
	ll f=1,x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-1;
	for (;isdigit(c);c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	return f*x;
}
int n,m,c,t,ans;
char a[N],b[N],cf[3]={'T','F','U'},opt[N];
int x[N],y[N];
void solve() {
	bool op=true;int con=0;
	for (int i=1;i<=n;i++) {
		b[i]=a[i];
		if (a[i]=='U') con++;
	}
	for (int i=1;i<=m;i++) {
		if (opt[i]=='+') a[x[i]]=a[y[i]];
		else if (opt[i]=='-') {
			if (a[y[i]]=='T') a[x[i]]='F';
			else if (a[y[i]]=='F') a[x[i]]='T';
			else a[x[i]]='U';
		} else a[x[i]]=opt[i];
	}
	for (int i=1;i<=n;i++) {
		if (b[i]!=a[i]) {
			op=false;
			break;
		}
	}
	if (op) {
		ans=min(ans,con);
//		for (int i=1;i<=n;i++) printf("%c",b[i]);
//		puts("");
//		printf("%d\n",con);
		return;
	}
}
void dfs(int pos) {
	if (pos==n+1) {
		solve();
		return;
	}
	for (int i=0;i<3;i++) {
		a[pos]=cf[i];
		dfs(pos+1);
	}
}
int main() {
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	c=read();t=read();
//	printf("%d %d\n",c,t);
	while (t--) {
		n=read();m=read();
//		puts("10000000");
//		printf("%d %d\n",n,m);
		for (int i=1;i<=m;i++) {
			scanf("%s",&opt[i]);
			x[i]=read();
			if (opt[i]=='+' || opt[i]=='-') y[i]=read();
			else y[i]=0;
//			if (y[i]!=0) printf("%c %d %d\n",opt[i],x[i],y[i]);
//			else printf("%c %d\n",opt[i],x[i]);
		}
		if (n<=10) {
			ans=n;dfs(1);
			printf("%d\n",ans);
		} else if (c==3 || c==4) {
			ans=0;
			for (int i=1;i<=n;i++) a[i]='?';
			for (int i=1;i<=m;i++) a[x[i]]=opt[i];
			for (int i=1;i<=n;i++) {
				if (a[i]=='U') ans++;
			}
			printf("%d\n",ans);
		} else if (c==5 || c==6) {
			ans=0;int oooooop=100;
			for (int i=1;i<=n;i++) a[i]='?';
			while (oooooop--) {
				int con=0;
				for (int i=1;i<=m;i++) {
					if (opt[i]=='+') a[x[i]]=a[y[i]];
					else a[x[i]]=opt[i];
				}
				for (int i=1;i<=n;i++)
					if (a[i]=='U') con++;
				ans=con;
			}
			printf("%d\n",ans);
		} else {
			ans=0;int oooooop=1000;
			for (int i=1;i<=n;i++) a[i]='?';
			while (oooooop--) {
				int con=0;
				for (int i=1;i<=m;i++) {
					if (opt[i]=='+') a[x[i]]=a[y[i]];
					else if (opt[i]=='-') {
						if (a[y[i]]=='T') a[x[i]]='F';
						else if (a[y[i]]=='F') a[x[i]]='T';
						else if (a[y[i]]=='U') a[y[i]]='U';
						else if (a[y[i]]=='?') a[y[i]]='?';
					}
					else a[x[i]]=opt[i];
				}
				for (int i=1;i<=n;i++)
					if (a[i]=='U') con++;
				ans=con;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
