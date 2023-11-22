#include <bits/stdc++.h>
using namespace std;
constexpr int max_n=/*100000*/200000;
int a[max_n+1];
int par[max_n+2];
int find(int&x){
	if(x>=0){
		if(x&&par[x]==-x){
			fprintf(stderr,"No solution\n");
			return x;
		}
		return par[x]!=x?x=find(par[x]):x;
	}
	x=-x;
	if(x&&par[x]==-x){
		fprintf(stderr,"No solution\n");
		return x;
	}
	// fprintf(stderr,"neg %d %d\n",x,par[x]);
	return par[x]!=x?x=-find(par[x]):(x=-x);
}
void test(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
		a[i]=i;
	const int tr=n+1;
	const int fal=-tr;
	for(int i=1,u,v; i<=m; ++i){
		char ch=getchar();
		if(ch=='+'){
			scanf("%d%d",&u,&v);
			a[u]=a[v];
			continue;
		}
		if(ch=='-'){
			scanf("%d%d",&u,&v);
			a[u]=-a[v];
			// fprintf(stderr,"%d: %d %d\n",u,v,-a[v]);
			continue;
		}
		if(ch=='T'){
			scanf("%d",&u);
			a[u]=tr;
			continue;
		}
		if(ch=='F'){
			scanf("%d",&u);
			a[u]=fal;
			continue;
		}
		if(ch=='U'){
			scanf("%d",&u);
			a[u]=0;
			continue;
		}
		--i;
	}
	for(int i=0; i<=tr; ++i)
		par[i]=i;
	for(int i=1; i<=n; ++i){
		int u=i,v=a[i];
		// fprintf(stderr,"%d: %d\n",u,v);
		find(u);
		find(v);
		// fprintf(stderr,"A(%d, %d)\n",u,v);
		if(u==v)
			continue;
		// fprintf(stderr,"B(%d, %d)\n",u,v);
		if(u+v==0)
			v=0;
		if(u==0||u==tr||u==fal)
			swap(u,v);
		if(u<0)
			u=-u,v=-v;
		// fprintf(stderr,"C(%d, %d)\n",u,v);
		if(u==0||u==tr||u==fal)
			fprintf(stderr,"No solution\n");
		par[u]=v;
	}
	int ans=0;
	for(int i=1; i<=n; ++i){
		int u=i;
		find(u);
		if(!u)
			++ans;
	}
	printf("%d\n",ans);
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int t;
	for(scanf("%*d%d",&t); t; test(),--t);
	return 0;
}