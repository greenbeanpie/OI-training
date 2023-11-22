#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,T,c;
char bh[N];
int zhi[N];
int qi[N],zho[N],w[N];
int ans=999999;
int fa[N],wt[N];
int find(int x){
	if(fa[x]!=x)
	return fa[x]=find(fa[x]);
	else 
	return x;
}
struct node{
	int to;
	int nt;
	int wt;
}edge[N];
int head[N],t;
void add(int a,int b,int wt){
	edge[++t].wt=wt;
	edge[t].to=b;
	edge[t].nt=head[a];
	head[a]=t;
}
int now[15],mu[15];
int baoli(){
	int cnt=1;
	for(int i=1;i<=n;i++)
	cnt*=3;
	cnt-=1;
	
	for(int j=cnt;j>=0;j--){
		int tmp=j;
		int an=0;
	for(int i=1;i<=n;i++)
	{
		now[i]=tmp%3;
		mu[i]=now[i];
		tmp/=3;
		if(now[i]==2)an++;
	}
	for(int i=1;i<=m;i++){
		if(bh[i]=='-'){
		if(mu[qi[i]]==1)mu[zho[i]]=0;
   		if(mu[qi[i]]==0)mu[zho[i]]=1;
   		if(mu[qi[i]]==2)mu[zho[i]]=2;
	   }
	   if(bh[i]=='+'){
   		if(mu[qi[i]]==1)mu[zho[i]]=1;
   		if(mu[qi[i]]==0)mu[zho[i]]=0;
   		if(mu[qi[i]]==2)mu[zho[i]]=2;
	   }
	   if(bh[i]=='T'){
   		mu[zhi[i]]=1;
	   }
	   if(bh[i]=='F'){
   		mu[zhi[i]]=0;
	   }
	   if(bh[i]=='U'){
   		mu[zhi[i]]=2;
	   }
	}
	bool pd=1;
	for(int i=1;i<=n;i++)
	if(now[i]!=mu[i])pd=0;
	if(pd)ans=min(ans,an);
	}
}
void bao(){
	int ans=0;
	for(int i=1;i<=m;i++)
	if(bh[i]=='U'){
   		ans++;
	   }
}
int main(){
	freopen("tribool.in","r",in);
	freopen("tribool.in","w",out);
	cin>>c>>T;,
	while(T--){
    memset(edge,0,sizeof(edge));
	memset(head,0,sizeof(head));
	ans=9999999;
	cin>>n>>m;
	int x,y;
   for(int i=1;i<=m;i++){
   	cin>>bh[i];
   if(bh[i]=='-'){
   		cin>>x>>y;
   		add(y,x,1);
   		qi[i]=y;zho[i]=x;w[i]=1;
	   }
  if(bh[i]=='+'){
   		cin>>x>>y;
   		add(y,x,1);
   		qi[i]=y;zho[i]=x;w[i]=0;
	   }
	   if(bh[i]=='T'){
   		cin>>x;
   		zhi[i]=x;
	   }
	   if(bh[i]=='F'){
   		cin>>x;
   		zhi[i]=x;
	   }
	   if(bh[i]=='U'){
   		cin>>x;
   		zhi[i]=x;
	   }
   }
   if(c==1||c==2)baoli();
   if(c==3||c==4)bao();
   cout<<ans<<endl;
	}
}
