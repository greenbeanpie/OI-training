#include<bits/stdc++.h>
using namespace std;
int C,T;
int n,m;
int cnt;
int fa[400010];
int id[100010];
int find(int x){
	assert(x!=0);
	// cerr<<"find"<<x<<" "<<fa[x]<<"\n";
	// if(fa[x]==0) exit(0);
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
	// cerr<<x<<" "<<y<<"\n";
	// printf("x:%d,y:%d,%d %d\n",x,y,find(x),find(y));
	fa[find(x)]=find(y);
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&C,&T);
	// T=2;
	while(T--){
		scanf("%d%d",&n,&m);
		// cerr<<n<<" "<<m<<"\n";
		for(int i=1;i<=n+n+3;++i) fa[i]=i;
		for(int i=1;i<=n;++i) id[i]=2*i+2;
		cnt=n+n+3;
		// cerr<<cnt<<"\n";
		for(int i=1;i<=m;++i){
			// cerr<<i<<"\n";
			// printf("i:%d\n",i);
			char c=getchar();
			while(c!='+'&&c!='-'&&c!='T'&&c!='F'&&c!='U') c=getchar();
			// scanf("%c",&c);
			if(c=='+'){
				int u,v;
				scanf("%d%d",&u,&v);
				++cnt;
				fa[cnt]=find(id[v]);
				++cnt;
				fa[cnt]=find(id[v]+1);
				id[u]=cnt-1;
			}
			else if(c=='-'){
				int u,v;
				scanf("%d%d",&u,&v);
				++cnt;
				fa[cnt]=find(id[v]+1);
				++cnt;
				fa[cnt]=find(id[v]);
				id[u]=cnt-1;
			}
			else {
				int u;scanf("%d",&u);
				++cnt;
				if(c=='U'){
					fa[cnt]=3;fa[++cnt]=3;
				}
				else if(c=='F'){
					fa[cnt]=1;fa[++cnt]=2;
				}
				else{
					fa[cnt]=2;fa[++cnt]=1;
				}
				id[u]=cnt-1;
			}
		}
		// cerr<<"get\n";
		// cerr<<cnt<<"\n";
		int ans=0;
		for(int i=1;i<=n;++i){
			// printf("i:%d\n",i);
			merge(2*i+2,id[i]);
			merge(2*i+3,id[i]+1);
		}
		for(int i=1;i<=n;++i){
			// printf("i:%d,%d,%d %d,%d\n",i,id[i],find(id[i]),find(id[i]+1),find(3));
			if(find(id[i])==find(id[i]+1)||find(id[i])==find(3)) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}