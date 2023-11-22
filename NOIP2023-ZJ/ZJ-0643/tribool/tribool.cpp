#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100010,M=100010;
int c,t;
int n,m;
int fa[N],siz[N];
int d[N],edge[N],v[N];
int z[N];
void init(){
	for(int i=1;i<=n;i++){
		siz[i]=1;
		fa[i]=i;
		edge[i]=1;
		d[i]=0;
		v[i]=0;
	}
}
int gt(int x){
	if(x==fa[x])return x;
	int r=gt(fa[x]);
	edge[x]*=edge[fa[x]];
	fa[x]=r;
	return fa[x];
}
void mer(int x,int y,int k){
	int p=gt(x),q=gt(y);
	if(p==q)return;
	fa[p]=q;
	siz[q]+=siz[p];
	d[q]=(d[q]|d[p]);
	edge[p]=k*edge[x]*edge[y];
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&m);
		init();
			for(int i=1;i<=m;i++){
				char w[5];
				int x,y;
				scanf("%s",w+1);
				if(w[1]=='T'||w[1]=='F'||w[1]=='U'){
					scanf("%d",&x);
					z[x]=(int)w[1];
					if(w[1]=='U'){
						d[gt(x)]=1;
					}
				}else{
					scanf("%d%d",&x,&y);
					int cal=0;
					if(w[1]=='+')cal=1;
					else cal=-1;
					if(gt(x)==gt(y)){
						if(edge[x]*edge[y]!=cal){
							d[gt(x)]=1;
						}
					}else mer(x,y,cal);
				}
			}
			int ans=0,ans2=0;
			for(int i=1;i<=n;i++){
				int r=gt(i);
				if(z[i]==int('U'))ans2++;
				if(v[r])continue;
				if(d[r]){
					ans+=siz[r],v[r]=1;
				}
			}
			if(c==3||c==4)printf("%d\n",ans2);
			else printf("%d\n",ans);	
	}
	return 0;
}

