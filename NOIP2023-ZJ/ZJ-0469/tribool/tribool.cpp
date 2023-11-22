#include<bits/stdc++.h>
//T-200002,F-200003,U-200004,Y--i*2,N--i*2+1
using namespace std;
struct tree{
	int nx;
}tr[100050];
int a[100050],head[200050],vis[100050],u,sum;
int n,m;
void dfs(int x,int num){
	if(x==0)return ;
	if(vis[x]&&num!=2){
		if(vis[x]!=num) u=1;
		return ;
	}
	if(vis[x]==2)return ;
	vis[x]=num;
	int pre=head[a[x]];
	while(pre){
		dfs(pre,num);
		if(u)return ;
		pre=tr[pre].nx;
	}
	 pre=head[a[x]^1];
	while(pre){
		if(num<2) dfs(pre,0-num);
		else dfs(pre,num);
		if(u)return ;
		pre=tr[pre].nx;
	}
	pre=head[x*2];
	while(pre){
		dfs(pre,num);
		if(u)return ;
		pre=tr[pre].nx;
	}
	pre=head[x*2^1];
	while(pre){
		if(num<2) dfs(pre,0-num);
		else dfs(pre,num);
		if(u)return ;
		pre=tr[pre].nx;
	}
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int C,T;
	cin>>C>>T;
while(T--){
	cin>>n>>m;
	int x,y;
	char v;
		for(int i=1;i<=n;i++){
			tr[i].nx=0;
			a[i]=i*2;
			vis[i]=0;
		}
		for(int i=2;i<=n*2+1;i++)head[i]=0;
		head[200002]=0;head[200003]=0;head[200004]=0;head[200005]=0;
	for(int i=1;i<=m;i++){
		v=getchar();
		while(!isalpha(v)&&v!='+'&&v!='-')v=getchar();
		if(v=='+'){
			scanf("%d%d",&x,&y);
			a[x]=a[y];
		}
		if(v=='-'){
			scanf("%d%d",&x,&y);
			a[x]=a[y]^1;
		}
		if(v=='T'){
			scanf("%d",&x);
			a[x]=200002;
		}
		if(v=='F'){
			scanf("%d",&x);
			a[x]=200003;
		}
		if(v=='U'){
			scanf("%d",&x);
			a[x]=200004;
		}
	}
	//for(int i=1;i<=n;i++)cout<<a[i]<<" ";cout<<endl;
	for(int i=1;i<=n;i++){
		tr[i].nx=head[a[i]];
		head[a[i]]=i;
	}
	/*
	for(int i=2;i<=n*2+1;i++){
		int u=head[i];
		cout<<i<<"  ";
		while(u){
			cout<<u<<" ";
			u=tr[u].nx;
		}cout<<endl;
	}*/
	sum=0;
	dfs(head[200002],1);
	dfs(head[200003],-1);
	dfs(head[200004],2);
	dfs(head[200005],2);
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		u=0;
		dfs(i,1);
		if(u==1){
			u=0;
			dfs(i,2);
		}
	}
	for(int i=1;i<=n;i++)sum+=vis[i]==2?1:0;
	//for(int i=1;i<=n;i++)cout<<vis[i]<<" ";cout<<endl;
	cout<<sum<<endl;
}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
