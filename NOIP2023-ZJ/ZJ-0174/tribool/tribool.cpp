#include<bits/stdc++.h>
using namespace std;
struct node{
	char ch;
	int x,y;
}b[100010];
int a[100010],A[100010],ans=0;
int c,T,n,m,ed[100010];
bool check(){
	for(int i=1;i<=n;i++)A[i]=a[i];
	for(int i=1;i<=m;i++){
		if(b[i].ch=='+')A[b[i].x]=A[b[i].y];
		else if(b[i].ch=='-'){
			if(A[b[i].y]>=0)A[b[i].x]=A[b[i].y]^1;
			else A[b[i].x]=A[b[i].y];
		}
		else{
			if(b[i].ch=='U')A[b[i].x]=-1;
			if(b[i].ch=='T')A[b[i].x]=1;
			if(b[i].ch=='F')A[b[i].x]=0;
		}
	}
	for(int i=1;i<=n;i++)
	    if(A[i]!=a[i])return false;
	return true;
}
void dfs(int x){
	if(x>n){
		int res=0;
		if(!check())return ;
		if(check()){
			for(int i=1;i<=n;i++)res+=(a[i]==-1);
			ans=min(ans,res);
		}
		return ;
	}
	for(int i=-1;i<=1;i++){
		a[x]=i;
		dfs(x+1);
	}
}
void solve1(){
	scanf("%d%d",&n,&m);ans=1e9;
	for(int i=1;i<=m;i++){
		char s[10];
		int x,y;
		scanf("%s",s);
		if(s[0]=='+'||s[0]=='-'){
			scanf("%d%d",&x,&y);
			b[i]=(node){s[0],x,y};
		}
		else{
			scanf("%d",&x);
			b[i]=(node){s[0],x,x};
		}
	}
	dfs(1);
	printf("%d\n",ans);
}
void solve2(){
	scanf("%d%d",&n,&m);ans=0;
	for(int i=1;i<=n;i++)a[i]=0;
	for(int i=1;i<=m;i++){
		char s[10];
		int x,y;
		scanf("%s",s);
		if(s[0]=='+'||s[0]=='-')scanf("%d%d",&x,&y);
		else{
			scanf("%d",&x);
			if(s[0]=='U')a[i]=1;
			else a[i]=0;
		}
	}
	for(int i=1;i<=n;i++)ans+=a[i];
	printf("%d\n",ans);
}
int main(){
	freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		if(c<=2)solve1();
		else if(c<=4)solve2();
	}
}