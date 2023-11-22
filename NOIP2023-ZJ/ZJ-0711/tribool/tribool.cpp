#include<bits/stdc++.h>
using namespace std;
int T,n,m,c,cnt;
char cc;
int ans=10000000;
int a[20],b[20],s[100010];
struct op{
	char v;
	int x,y;
}o[100010];
void check(){
	int sum=0;
	for(int i=1;i<=n;i++) {
		b[i]=a[i];
		if(a[i]==3) sum++;
	}
	for(int i=1;i<=m;i++){
		if(o[i].v=='T') b[o[i].x]=1;
		if(o[i].v=='F') b[o[i].x]=2;
		if(o[i].v=='U') b[o[i].x]=3;
		if(o[i].v=='+') b[o[i].x]=b[o[i].y];
		if(o[i].v=='-') {
			if(b[o[i].y]==3) b[o[i].x]=3;
			else{
				b[o[i].x]=3-b[o[i].y];
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(b[i]!=a[i]) return;
	}
	ans=min(ans,sum);
}
void dfs(int d){
	if(d==n+1) {
		check();
		return;
	}
	a[d]=1;
	dfs(d+1);
	a[d]=2;
	dfs(d+1);
	a[d]=3;
	dfs(d+1);
}
int main() {
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--) {
		ans=10000000;
		scanf("%d%d",&n,&m);
		cc=getchar();
		for(int i=1;i<=m;i++){
			o[i].v=getchar();
			cc=getchar();
			if(o[i].v=='+'||o[i].v=='-'){
				scanf("%d%d",&o[i].x,&o[i].y);
			}
			else{
				scanf("%d",&o[i].x);
			}
			cc=getchar();
		}
		if(c==1||c==2) {
			dfs(1);
			printf("%d\n",ans);
			continue;
		}
		if(c==3||c==4){
			memset(s,0,sizeof(s));
			for(int i=1;i<=m;i++){
				if(o[i].v=='T') s[o[i].x]=1;
				if(o[i].v=='F') s[o[i].x]=2;
				if(o[i].v=='U') s[o[i].x]=3;
			}
			int sum=0;
			for(int i=1;i<=n;i++){
				if(s[i]==3) sum++;
			}
			printf("%d\n",sum);
		}
	}
	return 0;
}
