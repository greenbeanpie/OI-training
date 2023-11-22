#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int C,T;
int n,m;
char opt[11];
int pre[N],fa[N],is[N],noo[N];
int vis[N],t[N];
int st[N],top;
struct node{
	int opt,x,y;
}q[N];
int ans,tmp[N],qwq[N];
void dfs(int u){
	if(u==n+1){
		for(int i=1;i<=n;i++) tmp[i]=pre[i];
		for(int w=1;w<=m;w++){
			int op=q[w].opt,x=q[w].x,y=q[w].y;
			if(op<=3){
				tmp[x]=op;
			}
			if(op==4){
				tmp[x]=tmp[y];
			}
			if(op==5){
				if(tmp[y]==1) tmp[x]=2;
				if(tmp[y]==2) tmp[x]=1;
				if(tmp[y]==3) tmp[x]=3;
			}
		}
		int cnt=0,tot=0;
		for(int i=1;i<=n;i++) cnt+=(tmp[i]!=pre[i]),tot+=(pre[i]==3);
		if(cnt==0&&tot==3) {
//			for(int i=1;i<=n;i++) printf("%d ",pre[i]);puts("");
//			for(int i=1;i<=n;i++) printf("%d ",tmp[i]);puts("");
			
			for(int w=1;w<=m;w++){
				int op=q[w].opt,x=q[w].x,y=q[w].y;
				if(op<=3){
					tmp[x]=op;
				}
				if(op==4){
					tmp[x]=tmp[y];
				}
				if(op==5){
//					printf("%d:%d ",x,tmp[x]);
					if(tmp[y]==1) tmp[x]=2;
					if(tmp[y]==2) tmp[x]=1;
					if(tmp[y]==3) tmp[x]=3;
//					printf("<-%d:%d \n",y,tmp[y]);
				}
			}
		}
		qwq[cnt]=min(qwq[cnt],tot);
		return;
	}
	pre[u]=1;
	dfs(u+1);
	pre[u]=2;
	dfs(u+1);
	pre[u]=3;
	dfs(u+1);
}

/*

1 1

10 10
- 7 3
- 5 3
+ 3 7
- 1 6
+ 4 6
- 8 4
- 6 8
+ 2 2
- 9 9
- 10 10
*/
inline void vio(){
	for(int i=0;i<=n;i++) qwq[i]=1e9;
	dfs(1);
	for(int i=0;i<=n;i++){
		if(qwq[i]!=1e9){
			printf("%d\n",qwq[i]);
			return;
		}
	}
}
inline void sol(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		pre[i]=fa[i]=is[i]=noo[i]=0;
		vis[i]=0;t[i]=0;
	}
	for(int i=1;i<=m;i++){
		scanf("%s",opt);
		int x,y;
		if(opt[0]=='T') {
			scanf("%d",&x);
			is[x]=1;
			q[i]={1,x};
		}
		if(opt[0]=='F') {
			scanf("%d",&x);
			is[x]=2;
			q[i]={2,x};
		}
		if(opt[0]=='U') {
			scanf("%d",&x);
			is[x]=3;
			q[i]={3,x};
		}
		if(opt[0]=='+') {
			scanf("%d%d",&x,&y);
			if(is[y]) is[x]=is[y];
			else{
				noo[x]=noo[y];
				if(fa[y]) fa[x]=fa[y];
				else fa[x]=y;
			}
			q[i]={4,x,y};
		}
		if(opt[0]=='-') {
			scanf("%d%d",&x,&y);
			if(is[y]){
				if(is[y]==1) is[x]=2;
				if(is[y]==2) is[x]=1;
				if(is[y]==3) is[x]=3;
			}
			else{
				noo[x]=noo[y]^1;
				if(fa[y]) fa[x]=fa[y];
				else fa[x]=y;
			}
			q[i]={5,x,y};
		}
	}
	if(n<=10){
		vio();
		return ;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			top=0;
			vis[i]=1;st[++top]=i;
			t[i]=0;int j=i;
			while(fa[j]&&vis[fa[j]]==0){
				t[fa[j]]=(t[j]^noo[j]);j=fa[j];
				vis[j]=1;st[++top]=j;
			}
//			printf(">%d [%d] rt:%d\n",i,top,j);
			if((fa[j]&&pre[j]==3)||(fa[j]&&t[fa[j]]!=t[j])){
				ans+=top;
				while(top){
					j=st[top--];
					pre[j]=3;
				}
			}
			else if(fa[j]&&pre[j]){
				int ch=pre[j];
				while(top){
					j=st[top--];
					pre[j]=ch;
				}
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		printf("%d:is %d,fa %d,xor %d,t:%d\n",i,is[i],fa[i],noo[i],t[i]);
//	}
	printf("%d\n",ans);
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);


//	freopen("tribool2.in","r",stdin);

	scanf("%d%d",&C,&T);
	while(T--) sol();
	return 0;
}

/*
1 1

10 10
- 7 3
- 5 3
+ 3 7
- 1 6
+ 4 6
- 8 4
- 6 8
+ 2 2
- 9 9
- 10 10
*/


/*
2 6
10 10
T 3
+ 1 2
- 7 1
+ 2 10
T 6
- 1 4
U 3
+ 7 10
F 5
+ 6 9
10 10
- 7 6
+ 4 1
+ 6 4
T 1
+ 2 9
- 9 10
U 10
+ 5 5
U 8
T 3
10 10
- 9 8
- 8 6
- 6 5
- 5 4
- 4 3
+ 3 9
- 1 2
+ 2 7
+ 7 10
- 10 1
10 10
- 7 5
+ 5 1
+ 1 7
+ 2 3
+ 3 4
+ 4 6
+ 6 8
- 8 9
+ 9 10
- 10 2
10 10
- 1 1
U 1
T 7
U 8
- 9 6
U 3
- 9 3
- 6 3
+ 9 3
- 9 8
10 10
- 7 3
- 5 3
+ 3 7
- 1 6
+ 4 6
- 8 4
- 6 8
+ 2 2
- 9 9
- 10 10

1
4
6
3
5
5

*/