#include<bits/stdc++.h>
using namespace std;
constexpr int M=1e5+5;queue<int>q;
vector<int>E[M],e[M];bool Flag,vis[M],flag[M];
int n,m,x,y,c,t,ans,sum,coef,f[M],g[M],col[M],deg[M];char op;
int read(){
	int x=0;char ch=getchar();
	while (!isdigit(ch)) ch=getchar();
	while (isdigit(ch)) x=x*10+ch-48,ch=getchar();
	return x;
}
char get(){
	char ch=getchar();
	while (ch!='+'&&ch!='-'&&ch!='T'&&ch!='U'&&ch!='F') ch=getchar();
	return ch;
}
void solve(){
	n=read();m=read();ans=0;
	for (int i=1;i<=n;i++) f[i]=4,deg[i]=0,g[i]=i,vis[i]=flag[i]=0;
	for (int i=1;i<=n;i++) E[i].clear(),e[i].clear();
	for (int i=1;i<=m;i++){
		op=get();x=read();
		if (op=='T') {f[x]=1;g[x]=0;continue;}
		if (op=='F') {f[x]=2;g[x]=0;continue;}
		if (op=='U') {f[x]=3;g[x]=0;continue;}
		y=read();
		if (op=='+'){
			if (g[y]) f[x]=f[y],g[x]=g[y];
			else f[x]=f[y],g[x]=0;
		}
		else{
			if (g[y]) f[x]=9-f[y],g[x]=g[y];
			else f[x]=f[y]==3?3:(3^f[y]),g[x]=0;
		}
	}
	for (int i=1;i<=n;i++)
		if (f[i]==4||f[i]==5)
			E[g[i]].push_back(i),
			e[i].push_back(g[i]),deg[g[i]]++;
	for (int i=1;i<=n;i++)
		if (f[i]>0&&f[i]<=3){
			coef=f[i]==3;q.push(i);
			while (!q.empty()){ ans+=coef;
				int x=q.front();vis[x]=1;q.pop();
				for (auto v:E[x])
					if (!vis[v]) q.push(v);
			}
		}
		else if (f[i]==0) vis[i]=1;
	for (int i=1;i<=n;i++)
		if (!vis[i]&&!deg[i])
			q.push(i);
	while (!q.empty()){
		int x=q.front();
		flag[x]=1;q.pop();
		for (auto v:e[x])
			if (!--deg[v])
				q.push(v);
	}
	for (int i=1;i<=n;i++)
		if (!vis[i]&&!flag[i]){
			sum=0;Flag=0;col[i]=0;
			q.push(i);while (!q.empty()){
				int x=q.front();q.pop();
				vis[x]=1;sum++;
				for (auto v:E[x]){
					const int c=f[v]==4?col[x]:!col[x];
					if (!vis[v]) col[v]=c,q.push(v);
					else if (col[v]!=c) Flag=1;
				}
			}
			ans+=sum*Flag;
		}
	printf("%d\n",ans);
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	c=read();t=read();
	while (t--) solve();
	return 0;
}