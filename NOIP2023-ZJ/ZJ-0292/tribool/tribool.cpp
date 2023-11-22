#include<bits/stdc++.h>
using namespace std;
int sum,i,c,t,n,m;
char x[100005],y[100005];
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while ((ch<'0'||ch>'9')&&(ch!='-')) ch=getchar();
	if (ch=='-'){
		f=-1;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=getchar();
	return x*f;	
}
struct node{
	int t,w;
	char c;
}d[100005];
inline bool pd(){
	for (int i=1;i<=n;i++) x[i]=y[i];
	for (int i=1;i<=m;i++)
		if (d[i].c=='-'){
			int t=d[i].t,w=d[i].w;
			if (x[w]=='T') x[t]='F';
			else if (x[w]=='F') x[t]='T';
			else x[t]=x[w];
		}
		else if (d[i].c=='+'){
			int t=d[i].t,w=d[i].w;
			x[t]=x[w];
		}
		else{
			x[d[i].t]=d[i].c;
		}
	for (int i=1;i<=n;i++)
		if (x[i]!=y[i]) return false;
	return true;
}
inline void dfs(int k,int s){
	if (s>=sum) return ;
	if (k>n){
		if (pd()) sum=min(sum,s);
		return ;
	}
	y[k]='T';
	dfs(k+1,s);
	y[k]='F';
	dfs(k+1,s);
	y[k]='U';
	dfs(k+1,s+1);
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	c=read();
	t=read();
	
	for (;t>=1;t--){
		n=read();
		m=read();
		bool f=true;
		for (i=1;i<=m;i++){
			char ch=getchar();
			while (ch!='-'&&ch!='+'&&ch!='T'&&ch!='F'&&ch!='U') ch=getchar();
			if (ch=='-'||ch=='+') d[i].c=ch,d[i].t=read(),d[i].w=read(),f=false;
			else d[i].c=ch,d[i].t=read();
		}
		if (f){
			sum=0;
			for (int i=1;i<=m;i++)
				y[d[i].t]=d[i].c;
			for (int i=1;i<=n;i++) if (y[i]=='U') sum++;
			printf("%d\n",sum);
			continue;
		}
		sum=n+1;
		dfs(1,0);
		printf("%d\n",sum);
	}
	return 0;
}