#include<bits/stdc++.h>
using namespace std;
int t1,t,n,m,x,y,ans;
char c;
int a[10010],f[10010][10];
bool count() {
	int b[10010];
	for (int i=1; i<=n; i++) {
		b[i]=a[i];
	}
	for (int i=1; i<=m; i++) {
		c=f[i][0];
		if (c=='+') {
			x=f[i][1];
			y=f[i][2];
			b[x]=b[y];
		}
		if (c=='-') {
			x=f[i][1];
			y=f[i][2];
			if (b[y]==2) {
				b[x]=b[y];
			} else {
				b[x]=!b[y];
			}
		}
		if (c=='T') {
			x=f[i][1];
			b[x]=1;
		}
		if (c=='F') {
			x=f[i][1];
			b[x]=0;
		}
		if (c=='U') {
			x=f[i][1];
			b[x]=2;
		}
	}
	for (int i=1; i<=n; i++)
		if (b[i]!=a[i]) {
			return 0;
		}
	return 1;
}
void tryy(int l,int s) {
	if (l>n) {
		if (count()) {
			if (s<ans)
				ans=s;
		}
		return;
	}
	for (int i=0; i<=2; i++) {
		a[l]=i;
		if (i==2) {
			tryy(l+1,s+1);
		} else {
			tryy(l+1,s);
		}
	}
}
void tryyy(int l,int s) {
	if (l>n) {
		if (count()) {
			if (s<ans)
				ans=s;
		}
		return;
	}
	for (int i=0; i<=2; i+2) {
		a[l]=i;
		if (i==2) {
			tryy(l+1,s+1);
		} else {
			tryy(l+1,s);
		}
	}
}
int main() {
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&t1,&t);
	if (t1<=2||t1>6) {
		for (int k=1; k<=t; k++) {
			scanf("%d%d",&n,&m);
			ans=n;
			for (int i=1; i<=m; i++) {
				getchar();
				c=getchar();
				if (c=='+') {
					scanf("%d%d",&x,&y);
					f[i][0]=c;
					f[i][1]=x;
					f[i][2]=y;
				}
				if (c=='-') {
					scanf("%d%d",&x,&y);
					f[i][0]=c;
					f[i][1]=x;
					f[i][2]=y;
				}
				if (c=='T') {
					scanf("%d",&x);
					f[i][0]=c;
					f[i][1]=x;
				}
				if (c=='F') {
					scanf("%d",&x);
					f[i][0]=c;
					f[i][1]=x;
				}
				if (c=='U') {
					scanf("%d",&x);
					f[i][0]=c;
					f[i][1]=x;
				}
			}
			tryy(1,0);
			printf("%d\n",ans);
		}
	} else if (t1<=4) {
		for (int k=1; k<=t; k++) {
			scanf("%d%d",&n,&m);
			memset(a,0,sizeof(a));
			for (int i=1; i<=m; i++) {
				getchar();
				c=getchar();
				if (c=='T') {
					scanf("%d",&x);
					a[x]=1;
				}
				if (c=='F') {
					scanf("%d",&x);
					a[x]=0;
				}
				if (c=='U') {
					scanf("%d",&x);
					a[x]=2;
				}
			}
			ans=0;
			for (int i=1; i<=n; i++)
				if (a[x]==2)
					ans++;
			printf("%d\n",ans);
		}
	} else if (t1<=6) {
		for (int k=1; k<=t; k++) {
			scanf("%d%d",&n,&m);
			ans=n;
			for (int i=1; i<=m; i++) {
				getchar();
				c=getchar();
				if (c=='+') {
					scanf("%d%d",&x,&y);
					f[i][0]=c;
					f[i][1]=x;
					f[i][2]=y;
				}
				if (c=='U') {
					scanf("%d",&x);
					f[i][0]=c;
					f[i][1]=x;
				}
			}
			ans=n;
			tryyy(1,0);
			printf("%d\n",ans);
		}
	}else if (t1<=8){
		for (int k=1; k<=t; k++) {
			scanf("%d%d",&n,&m);
			for (int i=1; i<=m; i++) {
				getchar();
				c=getchar();
				if (c=='+') {
					scanf("%d%d",&x,&y);
					f[i][0]=c;
					f[i][1]=x;
					f[i][2]=y;
				}
				if (c=='-') {
					scanf("%d%d",&x,&y);
					f[i][0]=c;
					f[i][1]=x;
					f[i][2]=y;
				}
			}
			ans=n;
			tryyy(1,0);
			printf("%d\n",ans);
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
