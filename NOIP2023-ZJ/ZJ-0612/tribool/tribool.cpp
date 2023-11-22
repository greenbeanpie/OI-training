#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;
int C,T,n,m,ans,b[100005],c[100005];
struct order{
	int op;
	int x,y,pos;
} f[100005];
bool check(){
	for(int i=1;i<=n;i++) c[i]=b[i];
	for(int i=1;i<=m;i++){
		if(f[i].op<=2) c[f[i].pos]=f[i].op;
		else{
			if(f[i].op==3) c[f[i].x]=c[f[i].y];
			else{
				if(c[f[i].y]==2) c[f[i].x]=c[f[i].y];
				else c[f[i].x]=(c[f[i].y]^1);
			}
		}
	}
	for(int i=1;i<=n;i++) if(c[i]!=b[i]) return false;
	return true;
}
int count(){
	int tot=0;
	for(int i=1;i<=n;i++) if(c[i]==2) tot++;
	return tot;
}
void dfs(int step){
	if(step==n+1){
		if(check()) ans=min(ans,count());
		return;
	}
	b[step]=0;
	dfs(step+1);
	b[step]=1;
	dfs(step+1);
	b[step]=2;
	dfs(step+1);
}
void work1(){
	ans=inf;
	dfs(1);
	printf("%d\n",ans);
}
void work2(){
	for(int i=1;i<=m;i++) b[f[i].pos]=f[i].op;
	int tot=0;
	for(int i=1;i<=n;i++) if(b[i]==2) tot++;
	printf("%d\n",tot);
}
void work3(){
	for(int i=1;i<=m;i++){
		if(f[i].op==3) b[f[i].x]=b[f[i].y];
		if(f[i].op==2) b[f[i].pos]=2;
	}
	int tot=0;
	for(int i=1;i<=n;i++) if(b[i]==2) tot++;
	printf("%d\n",tot);
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&C,&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) b[i]=-1;
		int flag1=1,flag2=1;
		for(int i=1;i<=m;i++){
			char c;
			cin>>c;
			if(c=='+'){
				flag1=0;
				f[i].op=3;
				scanf("%d%d",&f[i].x,&f[i].y);
			}
			if(c=='-'){
				flag1=flag2=0;
				f[i].op=4;
				scanf("%d%d",&f[i].x,&f[i].y);
			}
			if(c=='T'){
				flag2=0;
				f[i].op=0;
				scanf("%d",&f[i].pos);
			}
			if(c=='F'){
				flag2=0;
				f[i].op=1;
				scanf("%d",&f[i].pos);
			}
			if(c=='U'){
				f[i].op=2;
				scanf("%d",&f[i].pos);
			}
		}
		if(n<=10&&m<=10){
			work1();
			continue;
		}
		if(flag1){
			work2();
			continue;
		}
		if(flag2){
			work3();
			continue;
		}
	}
	return 0;
}
