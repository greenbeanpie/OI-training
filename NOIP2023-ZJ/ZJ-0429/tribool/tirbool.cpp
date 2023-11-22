#include<bits/stdc++.h>
using namespace std;
const int Maxn=100060;
int read() {
	int num=0,op=1;
	char c=getchar();
	while(c>'9'||c<'0') {
		if(c=='-') op=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		num=(num<<1)+(num<<3)+(c^48);
		c=getchar();
	}
	return op*num;
}
struct E{
	int from,to,dis;
}e[Maxn];
int n,m,tr[Maxn],nx[Maxn],ans=1000000;
void dfs(int dep){
	if(dep==n+1){
		for(int i=1;i<=n;i++)
			nx[i]=tr[i];
/*		for(int i=1;i<=n;i++)
		cout<<nx[i]<<" ";
		cout<<endl;*/
		for(int i=1;i<=m;i++){
			int u=e[i].from,v=e[i].to,dis=e[i].dis;
//			cout<<u<<' '<<v<<" "<<dis<<endl;
			if(u==0){
				nx[v]=dis;
			} else {
				nx[v]=nx[u]*dis;
			}
		}
/*		for(int i=1;i<=n;i++)
		cout<<nx[i]<<" ";
		cout<<endl;*/
		for(int i=1;i<=n;i++){
			if(tr[i]!=nx[i]) return;
		}
//		cout<<"OK"<<endl;
		int num=0;
		for(int i=1;i<=n;i++){
			if(tr[i]==0) num++;
		}
//		cout<<num<<endl;
		ans=min(ans,num);
		return;
	}
	for(int i=-1;i<=1;i++){
		tr[dep]=i;
		dfs(dep+1);
	}
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c=read(),T=read();
	while(T--) {
		n=read(),m=read();
		memset(e,0,sizeof(e));
		for(int i=1; i<=m; i++) {
			char op;
			cin>>op;
			if(op=='T') {
				int k=read();
				e[i].from=0;
				e[i].to=k;
				e[i].dis=1;
			}
			if(op=='F') {
				int k=read();
				e[i].from=0;
				e[i].to=k;
				e[i].dis=-1;
			}
			if(op=='U') {
				int k=read();
				e[i].from=0;
				e[i].to=k;
				e[i].dis=0;
			}
			if(op=='+') {
				int u=read(),v=read();
				e[i].from=v;
				e[i].to=u;
				e[i].dis=1;
			}
			if(op=='-') {
				int u=read(),v=read();
				e[i].from=v;
				e[i].to=u;
				e[i].dis=-1;
			}
		}
		if(n<=10){
			ans=19999999;
			dfs(1);
			cout<<ans<<endl;
		} else {
			ans=0;
			for(int i=1;i<=m;i++){
				int u=e[i].from,v=e[i].to,dis=e[i].dis;
				nx[v]=dis;
			}
			for(int i=1;i<=n;i++){
				if(nx[i]==0) ans++;
			}
			cout<<ans<<endl;
		}
	}
}
