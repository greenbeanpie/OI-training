#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define il inline
#define ll long long
il int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n,m;

//case 1,2
struct op1{
	string s;
	int x,y;
}c[15];
char a[15],b[15];
int ans;
il bool check(){
	for(int i=1;i<=n;i++) b[i]=a[i];
	for(int i=1;i<=m;i++){
		if(c[i].s=="T"||c[i].s=="F"||c[i].s=="U"){
			b[c[i].x]=c[i].s[0];
		}
		else{
			if(c[i].s=="+") b[c[i].x]=b[c[i].y];
			else{
				if(b[c[i].y]=='U') b[c[i].x]='U';
				else if(b[c[i].y]=='T') b[c[i].x]='F';
				else b[c[i].x]='T';
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=b[i]) return 0;
	}
	return 1;
}
il void dfs(int now=1,int sum=0){
	if(now==n+1){
		if(check()) ans=min(ans,sum);
		return;
	}
	a[now]='T';
	dfs(now+1,sum);
	a[now]='F';
	dfs(now+1,sum);
	a[now]='U';
	dfs(now+1,sum+1);
}

//case 3,4
char xx[N];

//case 5,6
int id[N];
bool is[N];
int in[N],last[N];
int fa[N],sz[N];
il int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
il void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx!=fy){
		sz[fy]+=sz[fx];
		fa[fx]=fy;
	}
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int Case=read(),T=read();
	if(Case<=2){
		while(T--){
			string s;
			int x,y;
			n=read(); m=read();
			for(int i=1;i<=m;i++){
				cin>>s;
				if(s=="T"||s=="F"||s=="U"){
					x=read();
					c[i]=op1{s,x,0};
					continue;
				}
				x=read(); y=read();
				c[i]=op1{s,x,y};
			}
			ans=n;
			dfs();
			cout<<ans<<endl;
		}
		return 0;
	}
	if(Case<=4){
		while(T--){
			string s;
			n=read(); m=read();
			for(int i=1;i<=n;i++) xx[i]='T';
			for(int i=1;i<=m;i++){
				cin>>s;
				if(s=="T"||s=="F"||s=="U"){
					int x=read();
					xx[x]=s[0];
				}
			}
			ans=0;
			for(int i=1;i<=n;i++)
				if(xx[i]=='U') ans++;
			cout<<ans<<endl;
		}
		return 0;
	}
	if(Case<=6){
		while(T--){
			n=read(); m=read();
			string s;
			int x,y;
			for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1; 
			memset(last,0,sizeof(last));
			memset(is,0,sizeof(is));
			memset(id,0,sizeof(id));
			for(int i=1;i<=m;i++){
				cin>>s;
				if(s=="U"){
					x=read();
					id[i]=x;
					is[last[x]]=1;
					last[x]=i;
				}
				else{
					x=read(); y=read();
					merge(x,y);
				}
			}
			memset(in,0,sizeof(in));
			ans=0;
			for(int i=1;i<=m;i++){
				if(id[i]&&!is[i]){
					int F=find(id[i]);
					if(!in[F]){
						in[F]=1;
						ans+=sz[F];
					}
				}
			}
			cout<<ans<<endl;
		}
		return 0;
	}
	return 0;
}

