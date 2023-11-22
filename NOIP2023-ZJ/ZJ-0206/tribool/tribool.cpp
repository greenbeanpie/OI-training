#include<bits/stdc++.h>
using namespace std;
#define N 100010
#define For(i,j,k) for(int i=j;i<=k;i++)
#define DFor(i,j,k) for(int i=j;i>=k;i--)
#define ll long long
int c,T,n,m;
int x[N],fa[N*2],tpe[2*N],rt[N*2];
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int p=find(x),q=find(y);
	if(p==q) return;
	if(tpe[q]!=-1) tpe[p]=tpe[q];
	fa[q]=p;
}
void work1(){
	For(i,1,2*n) tpe[i]=-1;
	For(i,1,2*n) fa[i]=i;
	For(i,1,n){
		if(x[i]==i) continue;
		if(x[i]>3*N){
			tpe[i]=x[i]-3*N;
			tpe[i+n]=3-tpe[i];
			if(tpe[i+n]==0) tpe[i+n]=3;
		} 
		else if(x[i]<0) merge(i,n-x[i]);
		else merge(i,x[i]);
	}
	For(i,1,2*n) rt[i]=find(i);
	For(i,1,n){
		if(rt[i]==rt[n+i]) tpe[rt[i]]=3;
	}
}
int tot,cnt[2*N],pos[2*N],tpe2[4*N],fa2[4*N],rt2[N*4];
int find2(int x){
	if(x==fa2[x]) return x;
	return fa2[x]=find2(fa2[x]);
}
void merge2(int x,int y){
	int p=find2(x),q=find2(y);
	if(p==q) return;
	if(tpe2[q]!=-1) tpe2[p]=tpe2[q];
	fa2[q]=p;
}
void work2(){
	tot=0;
	For(i,1,2*n) cnt[i]=0;
	For(i,1,4*n) tpe2[i]=-1,fa2[i]=i;
	For(i,1,2*n){
		if(cnt[rt[i]]==0){
			pos[rt[i]]=++tot;
			cnt[rt[i]]=1;
			tpe2[tot]=tpe[rt[i]];
		}
	}
	For(i,1,tot) if(tpe2[i]!=-1){
		tpe2[i+tot]=3-tpe2[i];
		if(tpe2[i+tot]==0) tpe2[i+tot]=3;
	}
	For(i,1,n){
		int u=rt[i],v=rt[n+i];
		u=pos[u],v=pos[v];
		if(u==v) continue;
		merge2(u,v+tot),merge2(v,u+tot);
	}
	For(i,1,tot){
		int u=find2(i),v=find2(i+tot);
		rt2[i]=u,rt2[i+tot]=v;
		if(u==v) tpe2[u]=3;
	}
}
char ch;
signed main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		scanf("%d%d",&n,&m);
		For(i,1,n) x[i]=i;
		while(m--){
			int u,v;
			ch=getchar();
			while(ch=='\n') ch=getchar();
			scanf("%d",&u);
			if(ch=='+'||ch=='-'){
				scanf("%d",&v);
				if(ch=='+') x[u]=x[v];
				else{
					if(x[v]<=3*N) x[u]=-x[v];
					else{
						x[u]=6*N+3-x[v];
						if(x[u]==3*N) x[u]+=3;
					}
				} 
			}else{
				if(ch=='T') x[u]=3*N+1;
				else if(ch=='F') x[u]=3*N+2;
				else if(ch=='U') x[u]=3*N+3;
			}
		}
		work1();work2();
		int ans=0;
		For(i,1,n){
			if(tpe[rt[i]]==3||tpe2[rt2[pos[rt[i]]]]==3) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}

