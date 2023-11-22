#include<bits/stdc++.h>

using namespace std;

const int MAXN=3000;

int read(){
	int x=0; bool f=0; char c;
	while(!isdigit(c=getchar())) if(c=='-') f=1;
	do x=x*10+c-48; while(isdigit(c=getchar()));
	return f?-x:x;
}

int C, n, m, T, a[MAXN], b[MAXN], pa[MAXN], pb[MAXN], va[MAXN], vb[MAXN], ra;
bool flag;
int f[MAXN][MAXN];
char ans[100];

int dfs(int now, int l)
{
//	cout<<now<<' '<<l<<endl;
//	if(now==5 && l==3) cout<<"yes\n";
	if(now==n+1) return l==m;
	if(f[now][l]!=-1) return f[now][l];
	int pos=l;
	while(pos<=m && (a[now]<b[pos]&&a[1]<b[1] || a[now]>b[pos]&&a[1]>b[1])) 
		++pos;
	--pos;
//	cout<<now<<' '<<l<<' '<<pos<<"****"<<endl;
//	if(now==4) cout<<l<<' '<<pos<<"abaaba\n";
	if(pos<l) return f[now][l]=0;
	if(now==n && pos==m) return f[now][l]=1;
	for(int i=l; i<=pos+1 && i<=m; ++i) if(dfs(now+1, i)) return f[now][l]=1;
	return f[now][l]=0;
}

void run()
{
	memset(f, -1, sizeof f);
	if(a[1]==b[1] || a[n]==b[m]) return ans[ra++]='0', void();
	if(a[1]>b[1] && a[n]<b[m] || 
		a[1]<b[1] && a[n]>b[m]) return ans[ra++]='0', void();
	ans[ra++]=dfs(1, 1)+'0';
}

signed main()
{
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	C=read(), n=read(), m=read(), T=read();
	for(int i=1; i<=n; i++) a[i]=read();
	for(int i=1; i<=m; i++) b[i]=read();
	run();
	while(T--){
		int kx=read(), ky=read();
		for(int i=1; i<=kx; i++)
			pa[i]=read(), va[i]=read(), swap(a[pa[i]], va[i]);
		for(int i=1; i<=ky; i++)
			pb[i]=read(), vb[i]=read(), swap(b[pb[i]], vb[i]);
		run();
//		cout<<ra<<endl;
//		if(ra==3){
//			for(int i=1; i<=n; i++) cout<<a[i]<<' '; cout<<endl;
//			for(int i=1; i<=m; i++) cout<<b[i]<<' '; cout<<endl;
//			cout<<endl;
//		}
		for(int i=1; i<=kx; i++)
			swap(a[pa[i]], va[i]);
		for(int i=1; i<=ky; i++)
			swap(b[pb[i]], vb[i]);
	}
	cout<<ans;
	return 0;
}
