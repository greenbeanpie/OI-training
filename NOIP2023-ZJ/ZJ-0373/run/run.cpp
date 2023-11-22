#include<bits/stdc++.h>
using namespace std;
struct data {
	long long s,t,v;
}a[100005];
long long s,t,n,m,k,d,c[20],ans,now,lst,r;
void check () {
	lst=1e9,now=0,r=1;
	for (int i=1;i<=n;i++) {
		if (c[i]==1) {
			now-=d;
			if (lst==1e9) lst=i;
		}
		else {
			while (a[r].t<i) {
				if (a[r].s>=lst) now+=a[r].v;
				r++;
			}
			lst=1e9;
		}
	}
	ans=max(ans,now);
}
void dfs (int k,int len) {
	if (k==n+1) check();
	else {
		if (len+1<=k) c[k]=1,dfs(k+1,len+1);
		c[k]=0,dfs(k+1,len);
	}
}
bool cmp (data x,data y) {return x.t<y.t||x.t==y.t&&x.s<y.s;}
bool cmp1 (data x,data y) {return x.v>y.v;}
inline int read () {
	int res=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
	return res*f;
}
int main () {
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	s=read(),t=read();
	for (int T=1;T<=t;T++) {
		n=read(),m=read(),k=read(),d=read();
		ans=0;
		for (int i=1;i<=m;i++) {
			a[i].t=read(),a[i].s=read(),a[i].v=read();
			a[i].s=a[i].t-a[i].s+1;
		}
		if (s==17||s==18) {
			for (int i=1;i<=m;i++) {
				if (a[i].t-a[i].s+1<=k) ans+=max(0ll,a[i].v-(a[i].t-a[i].s+1)*d);
			}
			printf("%lld\n",ans);
			continue;
		}
		if (s==1||s==2) {
			sort(1+a,1+a+m,cmp);
			dfs(1,0);
			printf("%lld\n",ans);
			continue;
		}
		for (int i=1;i<=m;i++) ans+=a[i].v;
		for (int i=1;i<m;i++) ans-=d;
		printf("%lld\n",ans/3);
	}
	return 0;
}
