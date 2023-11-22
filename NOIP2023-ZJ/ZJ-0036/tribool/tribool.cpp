#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;

int T;
int n,m;
char S[10];
pair<int,int> a[N];
int sz[N<<1],fa[N<<1];
bool U[N<<1];
int ans;

int get(int x) {
	if(fa[x]==x) return x;
	return fa[x]=get(fa[x]);
}

void merge(int x,int y) {
	x=get(x),y=get(y);
	if(x==y) return ;
	sz[x]+=sz[y],U[x]|=U[y],fa[y]=x;
}

int main() {
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%*d%d",&T);
	while(T--) {
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) a[i]={1,i};
		while(m--) {
			scanf("%s",S+1);
			if(S[1]=='T') {
				int x;
				scanf("%d",&x);
				a[x]={0,1};
			}
			else if(S[1]=='F') {
				int x;
				scanf("%d",&x);
				a[x]={0,-1};
			}
			else if(S[1]=='U') {
				int x;
				scanf("%d",&x);
				a[x]={0,0};
			}
			else if(S[1]=='+') {
				int x,y;
				scanf("%d%d",&x,&y);
				a[x]={a[y].first,a[y].second};
			}
			else if(S[1]=='-') {
				int x,y;
				scanf("%d%d",&x,&y);
				a[x]={a[y].first,-a[y].second};
			}
		}
		for(int i=1;i<=n+n;i++) fa[i]=i,sz[i]=1,U[i]=0;
		for(int i=1;i<=n;i++) {
			if(a[i].first==1) {
				if(a[i].second>0) merge(i,a[i].second),merge(i+n,a[i].second+n);
				else merge(i,-a[i].second+n),merge(i+n,-a[i].second);
			}
		}
		for(int i=1;i<=n;i++) {
			if(a[i].first==0) {
				if(a[i].second==0) U[get(i)]=U[get(i+n)]=1;
			}
			if(get(i)==get(i+n)) U[get(i)]=1;
		}
		ans=0;
		for(int i=1;i<=n+n;i++) if(get(i)==i && U[i]) ans+=sz[i];
		printf("%d\n",ans>>1);
	}
	return 0;
}
//9:20
