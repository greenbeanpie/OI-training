#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
void get(char &c){
	c=getchar();
	while(c!='-'&&c!='+'&&c!='T'&&c!='F'&&c!='U')c=getchar();
}
char c[150],ch;
int a[N],b[N],f[N],t[N],n,m,d[N];
vector<int>p[N];
vector<int>w[N];
void color(int u){
	t[u]=1;
	for (int i=0;i<d[u];i++){
		int v=p[u][i];
		if(t[v])continue;
		f[v]=w[u][i]?(3-f[u])%3:f[u];
		color(v);
	}
}
int dfs(int u,int z){
	if(t[u])return z==t[u];
	t[u]=z;
	for (int i=0;i<d[u];i++){
		int v=p[u][i];
		if(!dfs(v,w[u][i]?3-z:z)){t[u]=0;return 0;}
	}
	t[u]=0;
	return 1;
}
void work(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		a[i]=i,b[i]=0,f[i]=3,p[i].clear(),w[i].clear(),d[i]=0,t[i]=0;
	int u,v;
	for (int i=1;i<=m;i++){
		get(ch),scanf("%d",&u);
		if(ch=='-'||ch=='+'){
			scanf("%d",&v);
			if(f[v]!=3)
				a[u]=b[u]=0,f[u]=(ch=='-'?(3-f[v])%3:f[v]);
			else a[u]=a[v],b[u]=(b[v]+(ch=='-'))%2,f[u]=3;
		}
		else a[u]=b[u]=0,f[u]=c[ch];
	}
//	for (int i=1;i<=n;i++)printf("%d %d %d %d\n",i,a[i],b[i],f[i]);
	for (int i=1;i<=n;i++){
		if(f[i]==3){
			u=a[i],v=b[i];
			if(u==i&&v==1)f[i]=0;
			else if(u==i)continue;
			else {
				d[u]++,d[i]++;
				p[i].push_back(u),w[i].push_back(v);
				p[u].push_back(i),w[u].push_back(v);
			}
		}
	}
	for (int i=1;i<=n;i++)
		if(!t[i]&&f[i]!=3)color(i);
	for (int i=1;i<=n;i++)
		if(!t[i]){
			if(dfs(i,1))f[i]=1,color(i);
			else f[i]=0,color(i);
		}
	int k=0;
	for (int i=1;i<=n;i++)k+=(f[i]==0);
	printf("%d\n",k);
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	c['T']=1,c['F']=2,c['U']=0;
	int k;
	scanf("%d",&k),scanf("%d",&k);
	while(k--)work();
}
