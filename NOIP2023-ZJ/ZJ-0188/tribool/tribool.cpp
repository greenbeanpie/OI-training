#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int C,T,n,m,Ans,cnt,kkk[maxn],num[2*maxn];
struct yxy{
	char t;int x,y;
}qz[maxn];
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
int check(){
	for(int i=1;i<=n;i++)kkk[i]=num[i];
	for(int i=1;i<=m;i++){
		char ch=qz[i].t;
		if(ch=='+')kkk[qz[i].x]=kkk[qz[i].y];
		else if(ch=='-'){
			if(kkk[qz[i].y]==2)kkk[qz[i].x]=2;
			else kkk[qz[i].x]=(1^kkk[qz[i].y]);
		}
		else {
			if(ch=='U')kkk[qz[i].x]=2;
			else if(ch=='T')kkk[qz[i].x]=0;
			else kkk[qz[i].x]=1;
		}
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		if(num[i]!=kkk[i])return n+1;
		sum+=(num[i]==2);
	}
	return sum;
}
void dfs(int x){
	if(x>m){Ans=min(Ans,check());return;}
	num[x]=0;dfs(x+1);num[x]=1;dfs(x+1);num[x]=2;dfs(x+1);
}
void solve1(){
	while(T--){
		Ans=(1<<30);int x,y;
		n=read();m=read();
		memset(num,0,sizeof num);
		for(int i=1;i<=m;i++){
			char ch=getchar();
			while(ch!='T'&&ch!='U'&&ch!='F'&&ch!='+'&&ch!='-')ch=getchar();
			if(ch=='+')x=read(),y=read(),qz[i]=(yxy){ch,x,y};
			else if(ch=='-')x=read(),y=read(),qz[i]=(yxy){ch,x,y};
			else x=read(),qz[i]=(yxy){ch,x,0};
		}
		dfs(1);
		printf("%d\n",Ans);
	}
	exit(0);
}
void solve2(){
	while(T--){
		Ans=0;int x,y;
		n=read();m=read();
		memset(num,0,sizeof num);
		for(int i=1;i<=m;i++){
			char ch=getchar();
			while(ch!='T'&&ch!='U'&&ch!='F'&&ch!='+'&&ch!='-')ch=getchar();
			x=read(),qz[i]=(yxy){ch,x,0};
			if(ch=='U')num[qz[i].x]=2,Ans++;
			else if(ch=='T')num[qz[i].x]=0;
			else num[qz[i].x]=1;
		}
		printf("%d\n",Ans);
	}
	exit(0);
}
int tot,lnk[2*maxn],nxt[2*maxn],son[2*maxn],du[maxn];
void add_e(int x,int y){son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;du[y]++;}

void solve3(){
	while(T--){
		Ans=0;int x,y;
		n=read();m=read();
		memset(num,0,sizeof num);
		for(int i=1;i<=m;i++){
			char ch=getchar();
			while(ch!='T'&&ch!='U'&&ch!='F'&&ch!='+'&&ch!='-')ch=getchar();
			if(ch=='+'){
				x=read(),y=read(),qz[i]=(yxy){ch,x,y};
				add_e(y,x);
			}
			else {
				x=read(),qz[i]=(yxy){ch,x,0};
				num[x]=2;
			}
		}
		printf("%d\n",Ans);
	}
}
int dfn,top,id[2*maxn],stck[2*maxn],low[2*maxn],vis[2*maxn];
void Tarjan(int x){
	stck[++top]=x;
	low[x]=num[x]=++dfn;
	for(int j=lnk[x];j;j=nxt[j]){
		if(!num[son[j]])Tarjan(son[j]),low[x]=min(low[x],low[son[j]]);
		else if(!id[son[j]])low[x]=min(low[x],num[son[j]]);
	}
	if(low[x]==num[x]){
		if(stck[top]==x){
			top--;id[x]=++cnt;
		}else {
			vis[x]=2;id[x]=++cnt;
			while(stck[top]!=x){
				vis[stck[top]]=2;id[stck[top]]=cnt;
				top--;
			}
			top--;
		}
	}
}
void solve4(){
	while(T--){
		Ans=0;int x,y;
		n=read();m=read();
		memset(num,0,sizeof num);
		memset(id,0,sizeof id);
		memset(vis,0,sizeof vis);
		dfn=0;cnt=0;
		for(int i=1;i<=m;i++){
			char ch=getchar();
			while(ch!='T'&&ch!='U'&&ch!='F'&&ch!='+'&&ch!='-')ch=getchar();
			if(ch=='+')x=read(),y=read(),qz[i]=(yxy){ch,x,y},add_e(y,x);
			else if(ch=='-')x=read(),y=read(),qz[i]=(yxy){ch,x,y},add_e(n+y,x);
			else x=read(),qz[i]=(yxy){ch,x,0};
		}
		for(int i=1;i<=n;i++)add_e(i,n+i);
		for(int i=1;i<=n;i++)if(!num[i])Tarjan(i);
		for(int i=1;i<=n;i++)Ans+=(vis[i]==2);
		printf("%d\n",Ans);
	}
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	C=read();T=read();
	if(C==1||C==2)solve1();
	else if(C==3||C==4)solve2();
//	else if(C==5||C==6)solve3();
	else if(C==7||C==8)solve4();
	return 0;
}//dfs 10pts 10pts 3,4  5.6 10pts