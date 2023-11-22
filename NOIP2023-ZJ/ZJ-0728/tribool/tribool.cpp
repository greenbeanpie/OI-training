#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;

const int N=1e5+10;
const int inf=1e9;

int read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch<48||ch>57) {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>=48&&ch<=57) {
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}

int head[N],to[N*2],nxt[N*2],tot=0;
int tp[N];
void add(int u,int v,int typ) {
	nxt[++tot]=head[u];
	to[tot]=v;
	tp[tot]=typ;
	head[u]=tot;
}

int T;
struct sub {
	char ty;
	int u,v;
}a[N];
int n,m;
int b[N],c[N],d[N];
void clean() {
	memset(head,0,sizeof(head));
	tot=0;
	for(int i=1;i<=n;i++) d[i]=-2;
	 
}


int ans=inf;
void dfs(int x,int step) {
	if(step==n) {
		int cnt=0;
//		cout<<"%%%"<<endl;
		for(int i=1;i<=n;i++) {
			c[i]=b[i]=d[i];
//			cout<<b[i]<<" ";
			if(b[i]==0) cnt++;
		}
//		cout<<endl;
		for(int i=1;i<=m;i++) {
			char ty=a[i].ty;
			int u=a[i].u,v=a[i].v;
			if(ty=='+') {
				b[u]=b[v];
			} 
			if(ty=='-') {
				b[u]=-b[v];
			}
			if(ty=='T') {
				b[u]=1;
			}
			if(ty=='U') {
				b[u]=0;
			}
			if(ty=='F') {
				b[u]=-1;
			}
		}
		for(int i=1;i<=n;i++) {
			if(b[i]!=c[i]) {
				cnt=n;
				return ;
			}
		}
		ans=min(ans,cnt);
		return ;
	}
	for(int i=-1;i<=1;i++) {
		d[x]=i;
		dfs(x+1,step+1);	
	}
}

bool ck_only_TFU() {
	bool fl=1;
	for(int i=1;i<=m;i++) {
		char ty=a[i].ty;
		int u=a[i].u,v=a[i].v;
		if(ty=='+'||ty=='-') {
			fl=0;
			return false;
		}
		if(ty=='U') {
			d[u]=0;
		}
		if(ty=='F') {
			d[u]=-1;
		}
		if(ty=='T') {
			d[u]=1;
		}
	}
	ans=n;
	int cnt=0;
	for(int i=1;i<=n;i++) {
		if(d[i]==0) cnt++;
	}
	ans=min(ans,cnt);
	return true;
}

void sub1() {
	n=read();
	m=read();
	char ty;
	ans=n;
	int u,v;
	for(int i=1;i<=m;i++) {
		cin>>ty;
		a[i].ty=ty;
		u=read();
		a[i].u=u;
		a[i].v=0;
		if(ty=='+'||ty=='-') {
			v=read();
			a[i].v=v;
		} 
//		else {
//			if(ty=='U') a[u]=0;
//			if(ty=='T') a[u]=1;
//			if(ty=='F') a[u]=-1;
//		}	
	}
	
	dfs(1,0);
	printf("%lld\n",ans);
	
}

void sub2() {
	printf("%lld\n",ans);
}

void sub3() {
	printf("%lld\n",ans);
}

//void work() {
//	
//	int u,v,typ;
//	char ty;
//	n=read();
//	m=read();
//	for(int i=1;i<=m;i++) {
//		cin>>ty;
//		u=read();
//		if(ty=='+'||ty=='-') {
//			v=read();
//			if(ty=='+') typ=1;
//			else typ=-1;
//			add(u,v,typ);
//			if(a[v]!=-2) a[u]=typ*a[v]; 
//		} else {
//			if(ty=='U') a[u]=0;
//			if(ty=='T') a[u]=1;
//			if(ty=='F') a[u]=-1;
//		}	
//	}
//	
//} 

int ID;

signed main() {
	
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ID=read();
	T=read();
	while(T--) {
		clean();
		if(n<=10&&m<=10) sub1();
		else if(ck_only_TFU()) sub2();
		else  sub3();
	}

	return 0;
}


