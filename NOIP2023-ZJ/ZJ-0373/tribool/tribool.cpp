#include<bits/stdc++.h>
using namespace std;
struct data {
	char ch;
	int x,y;
}b[100005];
int son[100005],w[100005],nxt[100005],fir[100005],tot;
int son1[100005],nxt1[100005],fir1[100005];
void add (int x,int y,int z) {
	son[++tot]=y,w[tot]=z;
	nxt[tot]=fir[x],fir[x]=tot;
	son1[tot]=x;
	nxt1[tot]=fir1[y],fir1[y]=tot;
}
int s,t;
int n,m,a[100005],c[100005],ans,now;
int in[100005],q[100005],l,r,f[1000005],sum;
bool v[100005];
bool check () {
	for (int i=1;i<=n;i++) c[i]=a[i];
	for (int i=1;i<=m;i++) {
		if (b[i].ch=='+') c[b[i].x]=c[b[i].y];
		if (b[i].ch=='-') c[b[i].x]=-c[b[i].y];
		if (b[i].ch=='T') c[b[i].x]=1;
		if (b[i].ch=='F') c[b[i].x]=-1;
		if (b[i].ch=='U') c[b[i].x]=0;
	}
	for (int i=1;i<=n;i++) {
		if (c[i]!=a[i]) return false;
	}
	return true;
}
void dfs (int k,int len) {
	if (len>=ans) return ;
	if (k==n+1) {
		if (check()) ans=len;
	}
	else {
		a[k]=1,dfs(k+1,len);
		a[k]=-1,dfs(k+1,len);
		a[k]=0,dfs(k+1,len+1);
	}
}
int main () {
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&s,&t);
	if (s==1||s==2) {
		for (int T=1;T<=t;T++) {
			scanf("%d%d",&n,&m);
			for (int i=1;i<=m;i++) {
				cin>>b[i].ch;
				if (b[i].ch=='+'||b[i].ch=='-') scanf("%d%d",&b[i].x,&b[i].y);
				else scanf("%d",&b[i].x);
			}
			ans=1e9;
			dfs(1,0);
			printf("%d\n",ans);
		}
	}
	if (s==3||s==4) {
		for (int T=1;T<=t;T++) {
			scanf("%d%d",&n,&m);
			for (int i=1;i<=n;i++) c[i]=1;
			for (int i=1;i<=m;i++) {
				cin>>b[i].ch;
				scanf("%d",&b[i].x);
				if (b[i].ch=='T') c[b[i].x]=1;
				if (b[i].ch=='F') c[b[i].x]=-1;
				if (b[i].ch=='U') c[b[i].x]=0;
			}
			ans=0;
			for (int i=1;i<=n;i++) {
				if (c[i]==0) ans++;
			}
			printf("%d\n",ans);
		}
	}
	if (s==5||s==6) {
		for (int T=1;T<=t;T++) {
			scanf("%d%d",&n,&m);
			for (int i=1;i<=n;i++) c[i]=1;
			for (int i=1;i<=m;i++) {
				cin>>b[i].ch;
				if (b[i].ch=='U') {
					scanf("%d",&b[i].x);
					c[b[i].x]=0;
				}
				if (b[i].ch=='+') {
					scanf("%d%d",&b[i].x,&b[i].y);
					c[b[i].x]=c[b[i].y];
				}
			}
			ans=0;
			for (int i=1;i<=n;i++) {
				if (c[i]==0) ans++;
			}
			while (1) {
				for (int i=1;i<=m;i++) {
					if (b[i].ch=='U') c[b[i].x]=0;
					if (b[i].ch=='+') c[b[i].x]=c[b[i].y];
				}
				now=ans,ans=0;
				for (int i=1;i<=n;i++) {
					if (c[i]==0) ans++;
				}
				if (now==ans) break;
			}
			printf("%d\n",ans);
		}
	}
	if (s==7||s==8) {
		for (int T=1;T<=t;T++) {
			scanf("%d%d",&n,&m);
			for (int i=1;i<=n;i++) c[i]=1,in[i]=0,v[i]=false,f[i]=0;
			tot=0;
			for (int i=1;i<=n;i++) fir[i]=fir1[i]=0;
			for (int i=1;i<=m;i++) {
				cin>>b[i].ch;
				scanf("%d%d",&b[i].x,&b[i].y);
				if (b[i].ch=='+') add(b[i].y,b[i].x,1);
				if (b[i].ch=='-') add(b[i].y,b[i].x,-1);
				in[b[i].x]++;
			}
			for (int i=1;i<=n;i++) {
				if (in[i]==0) q[++r]=i;
			}
			while (l<=r) {
				for (int i=fir[q[l]];i;i=nxt[i]) {
					in[son[i]]--;
					if (in[son[i]]==0) q[++r]=son[i];
				}
				l++;
			}
			for (int i=1;i<=n;i++) {
				if (in[i]!=0&&!v[i]) {
					q[1]=i,l=r=1,f[i]=1,sum=0;
					while (l<=r) {
						for (int j=fir[q[l]];j;j=nxt[j]) {
							if (f[son[j]]!=0&&f[son[j]]!=f[q[l]]*w[j]) {
								sum=1;
								break;
							}
							if (f[son[j]]==0) {
								f[son[j]]=f[q[l]]*w[j];
								q[++r]=son[j];
								v[son[j]]=true;
							}
						}
						if (sum==1) break;
						l++;
					}
					if (sum==1) {
						q[1]=i,l=r=1;
						while (l<=r) {
							int xx=0;
							for (int j=fir[q[l]];j;j=nxt[j]) {
									xx++;
								if (c[son[j]]==1) {
									c[son[j]]=0;
									q[++r]=son[j];
								}
							}
							for (int j=fir1[q[l]];j;j=nxt1[j]) {
								if (c[son1[j]]==1) {
									c[son1[j]]=0;
									q[++r]=son1[j];
								}
							}
							l++;
						}
					}
				}
			}
			ans=0;
			for (int i=1;i<=n;i++) {
				if (c[i]==0) ans++;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
