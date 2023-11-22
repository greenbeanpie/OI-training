#include<bits/stdc++.h>
using namespace std;
const int N=2e5+110,M=2e5+110;
bool al1;
int c,T,ans;char opt;
int n,m,x[N],flag;//-3->U   -1->T   -2->F    -xi->i+n    xi->i
int f[N],knd[N],col[N],bk[N];
int check(int x){
	if(f[x]==x)return x;
	return f[x]=check(f[x]);
}
int head[N],tot,to[M],last[M];
void Dadd(int u,int v){
	to[++tot]=v,last[tot]=head[u],head[u]=tot;
	to[++tot]=u,last[tot]=head[v],head[v]=tot;
	return;
}
int fx(int u){
	if(u==-1)return -2;
	if(u==-2)return -1;
	return -3;
}
void dfs(int u,int cc){
	if(flag)return;
	col[u]=cc;
	for(int i=head[u];i;i=last[i]){
		int v=to[i];
		if(!col[v])dfs(v,3-cc);
		else if(col[v]==col[u]){flag=1;return;}
	}
}
void reward(int u){
	knd[u]=-3;
	bk[u]=1;
	for(int i=head[u];i;i=last[i]){
		int v=to[i];
		if(!bk[v])reward(v);
	}
	return;
}
void Stretch(int u,int cc){
	bk[u]=1;knd[u]=cc;
	for(int i=head[u];i;i=last[i]){
		int v=to[i];
		if(!bk[v])Stretch(v,fx(cc));
	}
	return;
}
void solve(){
	cin>>n>>m;ans=tot=0;
	for(int i=1;i<=2*n;i++){
		x[i]=knd[i]=col[i]=bk[i]=head[i]=0;
	}
	
	for(int i=1;i<=m;i++){
		cin>>opt;int tmp,tfa;
		if(opt=='T'){cin>>tmp;x[tmp]=-1;}
		if(opt=='F'){cin>>tmp;x[tmp]=-2;}
		if(opt=='U'){cin>>tmp;x[tmp]=-3;}
		if(opt=='+'){
			cin>>tmp>>tfa;
			if(x[tfa]==0)x[tmp]=tfa;
			else x[tmp]=x[tfa];
		}
		if(opt=='-'){
			cin>>tmp>>tfa;
			if(x[tfa]==0)x[tmp]=tfa+n;
			else if(x[tfa]==-1)x[tmp]=-2;
			else if(x[tfa]==-2)x[tmp]=-1;
			else if(x[tfa]==-3)x[tmp]=-3;
			else{
				if(x[tfa]>n)x[tmp]=x[tfa]-n;
				else x[tmp]=x[tfa]+n;
			}
		}
	}
//	for(int i=1;i<=n;i++)cerr<<x[i]<<" ";cerr<<endl;
	//1
	for(int i=1;i<=2*n;i++)f[i]=i;
	for(int i=1;i<=n;i++){
		if(x[i]>0){
			int A=check(i),B=check(x[i]);
			if(A!=B)f[A]=B;
		}
	}
	for(int i=1;i<=2*n;i++)f[i]=check(i);
//	for(int i=1;i<=2*n;i++)cerr<<f[i]<<" ";cerr<<endl;
	for(int i=1;i<=n;i++){
		if(f[i]!=f[i+n])Dadd(f[i],f[i+n]);
		else{
			knd[f[i]]=-3;
		}
	}
	for(int i=1;i<=n;i++)if(x[i]<0)knd[f[i]]=x[i];
	for(int i=1;i<=2*n;i++){
		if(f[i]!=i || !knd[i] || bk[i])continue;
		Stretch(i,knd[i]);
	}
	//3
	for(int i=1;i<=2*n;i++){
		if(f[i]!=i)continue;
		if(knd[i])continue;
		if(col[i])continue;
		flag=0;dfs(i,1);
		if(flag){
			reward(i);
		}
	}
	for(int i=1;i<=n;i++){
		if(knd[f[i]]==-3)ans++;
	}
	cout<<ans<<endl;
	return;
}
bool al2;
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0);
//	cerr<<(&al1-&al2)/1024.0/1024.0<<endl;;
	cin>>c>>T;
	while(T--)solve();
	return 0;
}
// now just use cin and cout
/*
1 1
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

*/