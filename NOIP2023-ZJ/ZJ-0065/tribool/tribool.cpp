#include<bits/stdc++.h>
using namespace std;
const int N=1e5+15;
int n,m;
int a[N];
int f[N<<1];
char id[3];
int getf(int x) {return f[x]==x?x:f[x]=getf(f[x]);}
void merge(int x,int y) {f[getf(x)]=getf(y);}
int main() {
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int Komeji,Koishi;scanf("%d%d",&Komeji,&Koishi);
	while(Koishi--) {
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) a[i]=i;
		while(m--) {
			int x,y;
			scanf("%s",id);
			if(id[0]=='T') {
				scanf("%d",&x);a[x]=n+1;
			}
			if(id[0]=='F') {
				scanf("%d",&x);a[x]=-(n+1);
			}
			if(id[0]=='U') {
				scanf("%d",&x);a[x]=0;
			}
			if(id[0]=='+') {
				scanf("%d%d",&x,&y);a[x]=a[y];
			}
			if(id[0]=='-') {
				scanf("%d%d",&x,&y);a[x]=-a[y];
			}
		}
		for(int i=1;i<=2*n+3;i++) f[i]=i;
		for(int i=1;i<=n;i++) {
			if(a[i]==0) merge(i,2*n+3),merge(i+n,2*n+3);
			else if(a[i]==n+1) merge(i,2*n+1),merge(i+n,2*n+2);
			else if(a[i]==-(n+1)) merge(i,2*n+2),merge(i+n,2*n+1);
			else if(a[i]>0) merge(i,a[i]),merge(i+n,a[i]+n);
			else merge(i,-a[i]+n),merge(i+n,-a[i]);
		}
		int ans=0;
		for(int i=1;i<=n;i++) {
			if(getf(i)==getf(i+n)) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
