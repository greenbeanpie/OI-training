#include<bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define fi first
#define se second
using namespace std;
template<typename T_>void operator+=(vector<T_>&x,const T_&y){x.push_back(y);}
template<typename T_>void Max(T_&x,const T_&y){if(y>x)x=y;}
template<typename T_>void Min(T_&x,const T_&y){if(y<x)x=y;}
int C,T,n,m;
int rv(int x){return x==2?2:!x;}
void work1(){
	int ans=INT_MAX;
	vector<int>w(15),ww;
	string ch(15,0);
	vector<pair<int,int>>op(15);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>ch[i]>>op[i].fi;
		if(ch[i]=='+'||ch[i]=='-')cin>>op[i].se;
	}
	for(int i=0,lim=(int)pow(3,n),res;i<lim;i++){
		res=0;
		for(int j=1,ii=i;j<=n;j++)w[j]=ii%3,ii/=3,res+=w[j]==2;
		ww=w;
		for(int j=1;j<=m;j++){
				 if(ch[j]=='-')ww[op[j].fi]=rv(ww[op[j].se]);
			else if(ch[j]=='+')ww[op[j].fi]=ww[op[j].se];
			else if(ch[j]=='F')ww[op[j].fi]=0;
			else if(ch[j]=='T')ww[op[j].fi]=1;
			else if(ch[j]=='U')ww[op[j].fi]=2;
		}
		if(ww==w)Min(ans,res);
	}
	cout<<ans<<'\n';
}
/*
int res;
bool flg;
vector<bool>vis;
vector<int>d;
vector<vector<pair<int,int>>>e;
void dfs(int u){
	res++;
	for(auto p:e[u]){
		int v=p.fi,w=p.se;
		if(vis[v]){
			if(d[v]!=(d[u]^w))flg=1;
		}
		else vis[v]=1,d[v]=d[u]^w,dfs(v);
	}
};
void work4(){
	cin>>n>>m;
	vector<bool>(n+1+7,false).swap(vis);
	vector<int>(n+1+7,0).swap(d);
	vector<vector<pair<int,int>>>(n+1+7).swap(e);
	char ch;
	for(int i=1,x,y;i<=m;i++){
		cin>>ch>>x>>y;
		if(ch=='+')e[x]+={y,0},e[y]+={x,0};
		else       e[x]+={y,1},e[y]+={x,1};
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		if(!vis[i])d[i]=res=flg=0,vis[i]=1,dfs(i),ans+=res*flg;
	cout<<ans<<'\n';
}
*/
void work2(){
	int ans=0;
	char ch;
	cin>>n>>m;
	vector<int>a(n+1+7,0);
	for(int i=1,x;i<=m;i++)
		cin>>ch>>x,a[x]=(ch=='U'?2:(ch=='T'?1:0));
	for(int i=1;i<=n;i++)ans+=a[i]==2;
	cout<<ans<<'\n';
}
void work3(){
	int ans=0;
	char ch;
	cin>>n>>m;
	vector<int>a(n+1+7,0);
	for(int i=1,x,y;i<=m;i++){
		cin>>ch>>x;
		if(ch=='+')cin>>y,a[x]=a[y];
		else a[x]=2;
	}
	for(int i=1;i<=n;i++)ans+=a[i]==2;
	cout<<ans<<'\n';
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>C>>T;
	while(T--){
		if(C<=2)work1();
		else if(C<=4)work2();
		else if(C<=6)work3();
//		else if(C<=8)work4();
	}
	return 0;
}
