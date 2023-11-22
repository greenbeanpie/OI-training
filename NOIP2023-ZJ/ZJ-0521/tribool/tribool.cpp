#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,c;
int n,m,fa[N],FA[N],ans,flag[N],mark[N];
int x[N],a[N],op1[N],op2[N];
char v[N][2];
int opp(int u){
	if(u==1)return 2;
	if(u==2)return 1;
	else return 3;
}
void dfs(int now){
	if(now==n+1){
		int sum=0;
		for(int i=1;i<=n;i++)a[i]=x[i];
		for(int i=1;i<=m;i++){
			if(v[i][1]=='+')a[op1[i]]=a[op2[i]];
			else if(v[i][1]=='-')a[op1[i]]=opp(a[op2[i]]);
			else if(v[i][1]=='T')a[op1[i]]=1;
			else if(v[i][1]=='F')a[op1[i]]=2;
			else a[op1[i]]=3;
		}
		for(int i=1;i<=n;i++)
			if(a[i]!=x[i])return;
			else if(a[i]==3)sum++;
		ans=min(ans,sum);
		return;
	}
	x[now]=1;dfs(now+1);
	x[now]=2;dfs(now+1);
	x[now]=3;dfs(now+1);
}
void work1(){
	dfs(1);
	printf("%d\n",ans);
}
void work2(){
	int sum=0;
	memset(x,0,sizeof x);
	for(int i=m;i>=1;i--){
		if(x[op1[i]])continue;
		if(v[i][1]=='T')x[op1[i]]=1;
		else if(v[i][1]=='F')x[op1[i]]=2;
		else x[op1[i]]=3,sum++;
	}
	printf("%d\n",sum);
}
int find(int u){
	if(u==fa[u])return u;
	return fa[u]=find(fa[u]);
}
int FIND(int u){
	if(u==FA[u])return u;
	return FA[u]=FIND(FA[u]);
}
bool chk(int u){
	if(u==FA[u])return false;
	int U=u;
	u=FA[u];
	while(u!=FA[u]&&u!=U)u=FA[u];
	if(U==u)return true;
	else return false;
}
void work3(){
	int sum=0;
	memset(flag,0,sizeof flag);
	memset(mark,0,sizeof mark);
	memset(x,0,sizeof x);
	for(int i=1;i<=n;i++)fa[i]=i,FA[i]=i;
	for(int i=m;i>=1;i--){
		if(v[i][1]=='U'){
			if(mark[op1[i]]){
				int f=find(op1[i]);
				x[f]=3;
			}
			else if(!flag[op1[i]]){
				flag[op1[i]]=1,x[op1[i]]=3;
			}
		}
		else{
			if(!flag[op1[i]]){
				FA[op1[i]]=op2[i],flag[op1[i]]=1;
				if(!mark[op1[i]]&&chk(op1[i])){
					int u=op2[i];
					mark[op1[i]]=1;
					while(u!=op1[i])fa[u]=op1[i],mark[u]=1,u=FA[u];
				}
			}
//			printf("%d\n",fa[op2[i]]);
		}
	}
	for(int i=1;i<=n;i++){
		int f;
		if(mark[i])f=find(i);
		else f=FIND(i);
		if(x[f]>0)sum++;
	}
	printf("%d\n",sum);
}
void solve(){
	ans=0x3f3f3f3f;
	int sum=0,sum2=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%s",v[i]+1);
		if(v[i][1]=='+'||v[i][1]=='-'){
			scanf("%d%d",&op1[i],&op2[i]);
			if(v[i][1]=='+')sum2++;
		}
		else{
			scanf("%d",&op1[i]);sum++;
			if(v[i][1]=='U')sum2++;
		}
	}
//	printf("%d\n",sum2);
	if(n<=10&&m<=10){work1();return;}
	else if(sum==m){work2();return;}
	else if(sum2==m){work3();return;}
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)solve();
	return 0;
}