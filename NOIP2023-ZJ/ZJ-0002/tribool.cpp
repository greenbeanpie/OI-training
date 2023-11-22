#include<bits/stdc++.h>
using namespace std;
constexpr int N=100000;
struct _{
	int x,tp;
}a[N+10];
int df[N+10],dsz[N+10],dw[N+10],tag[N+10];
int find(int x){
	if(x==df[x]) return x;
	int o=find(df[x]);
	dw[x]^=dw[df[x]],df[x]=o;
	return o;
}
void merge(int u,int v,int w){
	find(u),find(v);
	w^=dw[u]^dw[v],u=df[u],v=df[v];
	if(u!=v) dw[u]=w,df[u]=v,dsz[v]+=dsz[u],tag[v]|=tag[u];
	else if(w) tag[u]=1;
}
//int aans[N+10];
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		int n,m;
		cin>>n>>m;
		int i;
		for(i=1;i<=n;++i) a[i]={i,0};
		char ch[10];
		for(i=1;i<=m;++i){
			cin>>ch;
			int x,y;
			if(ch[0]=='T'){
				cin>>x;
				a[x]={0,0};
			}
			else if(ch[0]=='F'){
				cin>>x;
				a[x]={0,2};
			}
			else if(ch[0]=='U'){
				cin>>x;
				a[x]={0,1};
			}
			else if(ch[0]=='+'){
				cin>>x>>y;
				a[x]=a[y];
			}
			else{
				cin>>x>>y;
				a[x]=a[y];
				a[x].tp=2-a[x].tp;
			}
		}
		for(i=0;i<=n+2;++i) df[i]=i,dsz[i]=1,dw[i]=0,tag[i]=0;
		for(i=1;i<=n;++i){
			if(a[i].x) merge(i,a[i].x,a[i].tp);
			else if(a[i].tp==0) merge(i,n+1,0);
			else if(a[i].tp==2) merge(i,n+2,0);
			else merge(i,0,0);
		}
		tag[find(0)]=1;
		int ans=-1;
		for(i=0;i<=n+2;++i) if(df[i]==i&&tag[i]) ans+=dsz[i];
		cout<<ans<<'\n';
		/*
		for(i=1;i<=n;++i){
			if(find(i)==find(0)) aans[i]=1;
			else aans[i]=0;
		}
		for(i=1;i<=n;++i){
			int tmp;
			if(a[i].x) tmp=aans[a[i].x];
			else tmp=a[i].tp;
			if(tmp!=aans[i]) break;
		}
		cerr<<(i>n)<<'\n';
		*/
	}
	return 0;
}
