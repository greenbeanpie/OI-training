#include<bits/stdc++.h>
using namespace std;
int f[100001][2],n,m,t,c,ans=0,fa[100001],head[100001],tot=0,siz[100002],huan[100001],num[100001],cnt=0,pp[100001];
map<int,int> mp;
struct ngm{
	int to,nxt,z;
}e[100001];
void jh(int x){
	if(huan[x]) return;
	if(mp[x]){
		num[++cnt]=x;
		huan[x]=1;
		int y=fa[x];
		while(y!=x){
			huan[y]=1;
			y=fa[y];
		}
		mp[x]=0;
		return;
	}
	mp[x]=1;
	jh(fa[x]);
	mp[x]=0;
	return;
}
void add(int x,int y,int z){
	e[++tot].to=y;
	e[tot].nxt=head[x];
	e[tot].z=z;
	head[x]=tot;
}
int dfs(int x){
	for(int i=head[x];i;i=e[i].nxt){
		int y=e[i].to;
		fa[y]=x;
		if(y==fa[x] or huan[y]) continue;
		siz[x]+=dfs(y);
	}
	siz[x]+=1;
	return siz[x];
}

int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&m);
//		cout<<n<<" "<<m<<"\n";
		for(int i=1;i<=n;i++) f[i][0]=i,fa[i]=0,f[i][1]=0;
		for(int i=1;i<=m;i++){
			char op;
			cin>>op;
			if(op=='T' or op=='F' or op=='U'){
				int u;
				scanf("%d",&u);
				int v=0;
				if(op=='T') v=0;
				else if(op=='F') v=-1;
				else v=-2;
				f[u][0]=v;f[u][1]=0;
			}
			else {
				int u,v;
				scanf("%d%d",&u,&v);
				f[u][0]=f[v][0];
				f[u][1]=f[v][1];
				if(op=='-') {
					f[u][1]=1-f[u][1];
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(f[i][0]<=0 or f[i][0]==i) fa[i]=i,pp[i]=1;
			else{
				fa[i]=f[i][0];pp[f[i][0]]=1;
				add(f[i][0],i,f[i][1]);
			}
		}
//		for(int i=1;i<=n;i++) printf("%d ",fa[i]);
//		printf("\n");
		for(int i=1;i<=n;i++)if(pp[i]) jh(i);
//		for(int i=1;i<=n;i++) printf("%d ",huan[i]);
//		printf("%d\n");
		for(int i=1;i<=n;i++){
			if(huan[i]) dfs(i);
		}
//		for(int i=1;i<=cnt;i++) cout<<num[i]<<" ";
//		cout<<"\n";
		for(int i=1;i<=cnt;i++){
			if(f[num[i]][0]<=0){
				if(f[num[i]][0]==-2)ans+=siz[num[i]];
				continue;
			}
			int y=fa[num[i]];
			int sans=f[num[i]][1];
			while(y!=num[i]){
				if(f[y][1]==1) sans=1-sans;
				y=fa[y];
			}
			if(sans==1){
				y=fa[num[i]];
				ans+=siz[num[i]];
				while(y!=num[i]){
					ans+=siz[y];
					y=fa[y];
				}
			}
		}
		for(int i=0;i<=n;i++){
//			printf("T%d %d: %d %d %d %d\n",t,i,f[i][0],f[i][1],siz[i],fa[i]);
			f[i][0]=0,f[i][1]=0;head[i]=0;siz[i]=0;huan[i]=0;mp[i]=0,pp[i]=0;
		} 
		for(int i=1;i<=tot;i++){
			e[i].to=0,e[i].nxt=0,e[i].z=0;
		}
		for(int i=1;i<=cnt;i++){
			num[i]=0;
			
		}
		fa[0]=0;
		tot=0;
		cnt=0;
		printf("%d\n",ans);
		ans=0;
	}
}

