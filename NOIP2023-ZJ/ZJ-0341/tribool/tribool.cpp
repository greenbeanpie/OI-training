#include<bits/stdc++.h>
using namespace std;

int read(){
	int x=0,f=1;char c;c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ x=x*10+(c-48);c=getchar();}
	return x*f;
}

const int maxn=1e5+10;

int num,t,n,m;
int a[maxn],pre[maxn];//0=F  1=T  2=U
int op[maxn];//F T U + -
int loc[maxn][2];//0 <- 1
int ans=maxn;

void init(){
	for(int i=0;i<=n;i++) a[i]=pre[i]=-1,fa[i]=i,vis[0];
	for(int i=0;i<=m;i++) loc[i][0]=loc[i][1]=op[i]=0;
	ans=maxn;
}

void carry(int idx){
	if(op[idx]==0) pre[loc[idx][0]]=0;
	if(op[idx]==1) pre[loc[idx][0]]=1;
	if(op[idx]==2) pre[loc[idx][0]]=2;
	if(op[idx]==3) pre[loc[idx][0]]=pre[loc[idx][1]];
	if(op[idx]==4){
		if(a[loc[idx][1]]==2) pre[loc[idx][0]]=pre[loc[idx][1]];
		else pre[loc[idx][0]]=1-pre[loc[idx][1]];
	}
}

void dfs(int step){
	if(step>n){
		for(int i=1;i<=n;i++) pre[i]=a[i];
		for(int i=1;i<=m;i++) carry(i);
		int f=1,tot=0;;
		for(int i=1;i<=n;i++){
			if(a[i]!=pre[i]){
				f=0;break;
			}
			if(pre[i]==2) tot++;
		}
		if(f) ans=min(tot,ans);
		return;
	}
	for(int i=0;i<3;i++){
		a[step]=i;
		dfs(step+1);
	}
}

int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	num=read(),t=read();
	while(t--){
		n=read(),m=read();
		init();
		for(int i=1;i<=m;i++){
			char s;
			s=getchar();
			if(s=='F'){
				op[i]=0;loc[i][0]=read();
			}
			if(s=='T'){
				op[i]=1;loc[i][0]=read();	
			}
			if(s=='U'){
				op[i]=2;loc[i][0]=read();
			}
			if(s=='+'){
				loc[i][0]=read(),loc[i][1]=read();op[i]=3;
			}
			if(s=='-'){
				loc[i][0]=read(),loc[i][1]=read();op[i]=4;
			}
		}
		if(num<=2){
			dfs(1);
			printf("%d\n",ans);
		}
		if(num>=3&&num<=4){
			for(int i=1;i<=m;i++){
				if(op[i]==0) a[i]=0;
				if(op[i]==1) a[i]=1;
				if(op[i]==2) a[i]=2;
			}
			int tot=0;
			for(int i=1;i<=n;i++) if(a[i]==2) tot++;
			printf("%d\n",tot);
		}
	}
	return 0;
}